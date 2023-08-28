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
            
            for (int character{0}; character < character; character++)
            {
                m_data[character] = data.m_data[character];
            }
            
            return *this;
        }
        
        // Move constructor
        String(String&& data) noexcept
            : m_size{ data.m_size }, m_data{ std::move(data.m_data) }
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
            
            for (const char* nullTerminator{data}; *nullTerminator != '\0'; nullTerminator++)
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

        namespace Constants
        {
            constexpr double PI = 3.14159265358979323846;
            constexpr double EULERS = 2.71828182845904523536;
            constexpr double GOLDEN_RATIO = 1.61803398874989484820;
            constexpr int SPEED_OF_LIGHT = 186282;            
        }

        template <typename T, typename U>
        class Vector2
        {
        public:
            /* CONSTRUCTORS */
            Vector2() 
            {
                this->m_x = 0;
                this->m_y = 0;
            }

            Vector2(T x)
                : m_x{ x }, m_y{ 0 }
            {}

            Vector2(T x, U y)
                : m_x{ x }, m_y{ y }
            {}

            /* DESTRUCTORS */
            ~Vector2() = delete;

            // Copy constructor
            Vector2(const Vector2& obj)
                : m_x{ obj.m_x }, m_y{ obj.m_y }
            {}

            // Copy assignment
            Vector2& operator=(const Vector2& obj)
            {
                if (this == &data)
                    return *this;
                
                this->m_x = obj.m_x;
                this->m_y = obj.m_y;

                return *this;
            }

            // Move constructor
            Vector2(Vector&& obj) noexcept
                : m_x{ std::move(obj.m_x) }, m_y{ std::move(obj.m_y) }
            {
                obj.m_x = 0;
                obj.m_y = 0;
            }

            // Move assignment
            Vector2& operator=(Vector2&& obj) noexcept
            {
                if (this == &data)
                    return *this;
                
                this->m_x = std::move(obj.m_x);
                this->m_y = std::move(obj.m_y);
                
                obj.m_x = 0;
                obj.m_y = 0;

                return *this;
            }

            /* OPERATORS OVERLOADS */
            

            /* PUBLIC GETTERS */
            // Returns the x member variable
            const U& getX() const noexcept
            {
                return m_x;
            }

            // Returns the y member variable
            const T& getX() const noexcept
            {
                return m_y;
            }

            /* EXTERNS/OVERRIDES */
            // Print out the object
            friend std::ostream& operator<<(std::ostream& out, const Vec2<T,U>& obj)
            {
                out << "( " << obj.m_x << ", " << obj.m_y << ")";
                return out;
            }
        private:
            /* Member variables */
            T m_x{};
            U m_y{};
        }; template<typename T, typename U> using Vec2 = Vector2<T, U>;
    }
}

#endif /* UTILS_H */
