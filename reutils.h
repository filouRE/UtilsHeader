#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <memory>

namespace Utils
{
    class String
    {
    public:
        // Default constructor
        String()
            : m_data{ nullptr }
        {}
    
        // String constructor
        String(const char* string)
            : m_size{ getSize(string) }
        {
            m_data = std::make_unique<char[]>(m_size);
        
            for (int it = 0; it < m_size; it++)
            {
                m_data[it] = string[it];
            }
        }
    
        // Copy constructor
        String(const String& data)
            : m_size{ data.m_size }
        {
            m_data = std::make_unique<char[]>(m_size);
        
            for (int it = 0; it < m_size; it++)
            {
                m_data[it] = data.m_data[it];
            }
        }
    
        // Copy assignment
        String& operator=(const String& data)
        {
            if (this == &data)
                return *this;
            
            m_size = data.m_size;
            m_data = std::make_unique<char[]>(m_size);
            
            for (int it = 0; it < m_size; it++)
            {
                m_data[it] = data.m_data[it];
            }
            
            return *this;
        }
        
        // Move constructor
        String(String&& data) noexcept
            : m_size(data.m_size), m_data(std::move(data.m_data))
        {
            data.m_size = 0;
            data.m_data = nullptr;
        }
        
        // Move assignment
        String& operator=(String&& data) noexcept
        {
            if (this == &data)
                return *this;
            
            m_size = data.m_size;
            m_data = std::move(data.m_data);
            
            data.m_size = 0;
            data.m_data = nullptr;
            
            return *this;
        }
        
        // Destructor
        ~String() = default;
        
        /* PUBLIC GETTERS */
        // Returns Length of the string
        int Length() const
        {
            return m_size;
        }
        
        /* EXTERNS/OVERRIDES */
        // Print out the object
        friend std::ostream& operator<<(std::ostream& out, const String& obj)
        {
            return out << obj.getData();
        }
        
    private:
        /* PRIVATE GETTERS */
        // Calculate and Returns the number of characters in the string
        int getSize(const char* data) const
        {
            int size = 0;
            
            for (const char* nullTerminator = data; *nullTerminator != '\0'; nullTerminator++)
            {
                size++;
            }
            
            return size;
        }
        
        // Returns the string
        const char* getData() const
        {
            if (!m_data)
                throw std::runtime_error("error, string is empty");
            
            return m_data.get();
        }
    
    private:
        /* Member variables */
        std::unique_ptr<char[]> m_data;
        int m_size = 0;
    };
    namespace Math
    {
        // TODO - Add more math functions && constants
    }
}

#endif /* UTILS_H */
