//
//  CsvParser.cpp
//  NewGame
//
//  Created by 胡可 on 15/9/29.
//
//
#include "cocos2d.h"
#include "CsvParser.h"

namespace Parser {
    
    //Row
    Row::Row()
    {
        
    }
    
    Row::~Row()
    {
        
    }
    
    void Row::push_back(const std::string &_value)
    {
        m_values.push_back(_value);
    }
    
    void Row::setHeader(const std::vector<std::string> *_header)
    {
        m_header = _header;
    }
    
    std::string& Row::operator[](unsigned int _key)
    {
        if(_key < size())
        {
            return m_values[_key];
        }
        throw "can't return this value (doesn't exist)";
    }
    
    std::string& Row::operator[](const std::string &_key)
    {
        std::vector<std::string>::const_iterator it;
        int pos = 0;
        for (it = (*m_header).begin();it!=(*m_header).end();it++)
        {
            if(_key == *it)
            {
                return m_values[pos];
            }
            pos++;
        }
        throw "can't return this value (doesn't exist)";
    }


    
    //Csv
    
    Csv::Csv(const std::string& _filename)
    {
        Parser(_filename);
    }
    
    
    Csv::~Csv()
    {
        
    }
    
    void Csv::Load(const std::string &_filename, std::string &_Data)
    {
        FILE* pFile = fopen(_filename.c_str(), "rb");
        if(!pFile)
        {
            return;
        }
        fseek(pFile, 0, SEEK_END);
        long len = ftell(pFile);
        
        char* pBuffer = new char[len + 1];
        
        fseek(pFile, 0, SEEK_SET);
        fread(pBuffer, 1, len, pFile);
        fclose(pFile);
        
        pBuffer[len]=0;
        _Data.assign(pBuffer,len);
        
        delete[] pBuffer;
        
    }
    
    
    void Csv::Parser(const std::string &_filename)
    {
        m_content.clear();
        m_strErrorInfo.clear();
        
        std::string text;
        Load(_filename, text);
        
        if(text.size() == 0)
        {
            return;
        }
        
        enum CSV_STATE_TYPE
        {
            NewFieldStart,
            NonQuotesField,
            QuotesField,
            FieldSeparator,
            QuoteInQuotesField,
            RowSeparator,
            Error
        };
        
        Row Fields = Row();
        std::string strField;
        
        CSV_STATE_TYPE State = CSV_STATE_TYPE::NewFieldStart;
        
        for(int i = 0 ,size = (unsigned int)text.size();i<size;++i)
        {
           const char& ch = text[i];
            
            switch (State) {
                case NewFieldStart:
                {
                    if(ch == '"')
                    {
                        State = CSV_STATE_TYPE::QuotesField;
                    }
                    else if(ch == ',')
                    {
                        Fields.push_back("");
                        State = CSV_STATE_TYPE::FieldSeparator;
                    }
                    else if(ch == '\r' || ch == '\n')
                    {
                        m_strErrorInfo = "语法错误，有空行";
                        State = CSV_STATE_TYPE::Error;
                    }
                    else
                    {
                        strField.push_back(ch);
                        State = CSV_STATE_TYPE::NonQuotesField;
                    }
                }
                    break;
                case NonQuotesField:
                {
                    if(ch == ',')
                    {
                        Fields.push_back(strField);
                        strField.clear();
                        State = CSV_STATE_TYPE::FieldSeparator;
                    }
                    else if(ch == '\r')
                    {
                        Fields.push_back(strField);
                        State = CSV_STATE_TYPE::RowSeparator;
                    }
                    else
                    {
                        strField.push_back(ch);
                    }
                }
                    break;
                    
                case QuotesField:
                {
                    if(ch == '"')
                    {
                        State = CSV_STATE_TYPE::QuoteInQuotesField;
                    }
                    else
                    {
                        strField.push_back(ch);
                    }
                }
                    break;
                case FieldSeparator:
                {
                    if(ch == ',')
                    {
                        Fields.push_back("");
                    }
                    else if(ch == '"')
                    {
                        strField.clear();
                        State = CSV_STATE_TYPE::QuotesField;
                    }
                    else if(ch == '\r')
                    {
                        Fields.push_back("");
                        State = CSV_STATE_TYPE::RowSeparator;
                    }
                    else
                    {
                        strField.push_back(ch);
                        State = CSV_STATE_TYPE::NonQuotesField;
                    }
                }
                    break;
                case QuoteInQuotesField:
                {
                    if(ch == ',')
                    {
                        Fields.push_back(strField);
                        strField.clear();
                        State = CSV_STATE_TYPE::FieldSeparator;
                    }
                    else if(ch == '\r')
                    {
                        Fields.push_back(strField);
                        State = CSV_STATE_TYPE::RowSeparator;
                    }
                    else if(ch == '"')
                    {
                        strField.push_back(ch);
                        State = CSV_STATE_TYPE::QuotesField;
                    }
                    else
                    {
                        m_strErrorInfo = "语法错误：转义字符";
                        State = CSV_STATE_TYPE::Error;
                    }
                    
                    break;
                case RowSeparator:
                {
                    if(ch == '\n')
                    {
                        m_content.push_back(Fields);
                        Fields = Row();
                        strField.clear();
                        State = NewFieldStart;
                    }
                    else
                    {
                        m_strErrorInfo = "语法错误：行分隔用了回城";
                        State = CSV_STATE_TYPE::Error;
                    }
                    
                }
                    break;
                case Error:
                    {
                        return;
                    }
                    break;
                default:
                    break;
                }
            }

        }//end for
        
        switch (State) {
            case NewFieldStart:
            {

            }
                break;
            case NonQuotesField:
            {
                Fields.push_back(strField);
                m_content.push_back(Fields);
            }
                break;
            case QuotesField:
            {
                m_strErrorInfo = "语法错误，引号字段未闭合";
            }
                break;
            case FieldSeparator:
            {
                Fields.push_back("");
                m_content.push_back(Fields);
            }
                break;
                
            case QuoteInQuotesField:
            {
                Fields.push_back(strField);
                m_content.push_back(Fields);
            }
                break;
                
            case RowSeparator:
            {
                
            }
                break;
                
            case Error:
            {
                
            }
                break;
            default:
                break;
        }
        setHeader();
    }
    
    void Csv::setHeader()
    {
        m_header.clear();
        for(int i = 0;i<m_content[0].size();i++)
        {
            m_header.push_back(m_content[0][i]);
        }
        for(int i = 0; i < m_content.size();i++)
        {
            m_content[i].setHeader(&m_header);
        }
    }
    
    
    Row& Csv::operator[](unsigned int _key)
    {
        if(_key < m_content.size())
        {
            return m_content[_key];
        }
        throw "can't return this row (doesn't exist)";
        
        
    }

    
}