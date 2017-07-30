//
//  CsvParser.h
//  NewGame
//
//  Created by 胡可 on 15/9/29.
//
//

#ifndef CsvParser_h
#define CsvParser_h


#include <string>
#include <vector>

namespace Parser {
    
    //每一行的记录
    class Row
    {
    public:
        Row();
        ~Row();
        void push_back(const std::string& _value);
        void setHeader(const std::vector<std::string>* _header);
    public:
        inline unsigned int size() const {return (unsigned int)m_values.size();}
        std::string& operator[](unsigned int _key);
        std::string& operator[](const std::string& _key);
    private:
        const std::vector<std::string>* m_header;
        std::vector<std::string> m_values;
    };
    
    
    //Csv Parser
    class Csv
    {
    public:
        Csv(const std::string& _filename);
        ~Csv();
        void Parser(const std::string& _filename);
        Row& operator[](unsigned int _key);
    private:
        void Load(const std::string& _filename,std::string& _Data);
        void setHeader();
    public:
        inline const std::string& getErrorInfo() const {return m_strErrorInfo;}
        inline std::vector<std::string> getHeader() const {return m_header;}
        inline unsigned int getRowCount() const {return (unsigned int)m_content.size();}
        inline unsigned int getColumnCount() const {return (unsigned int)m_header.size();}
        
    private:
        std::vector<Row> m_content;
        std::vector<std::string> m_header;
        
        std::string m_strErrorInfo;
    };
    
}


#endif /* CsvParser_h */
