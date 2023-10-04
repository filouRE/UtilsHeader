#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <memory>
#include <algorithm>

namespace Utils
{
	class String
	{
	public:
		/* CONSTRUCTORS */
		// Default constructor
		String()
			: m_data{ nullptr }
		{
		}

		// String constructor
		String(const char* string)
			: m_size{ getSize(string) }
		{
			m_data = std::make_unique<char[]>(m_size);

			for (int it = 0; it < m_size; it++)
				m_data[it] = string[it];
		}

		// Copy constructor
		String(const String& data)
			: m_size{ data.m_size }
		{
			m_data = std::make_unique<char[]>(m_size);

			for (int it = 0; it < m_size; it++)
				m_data[it] = data.m_data[it];
		}

		// Copy assignment
		String& operator=(const String& obj)
		{
			if (this == &obj)
				return *this;

			m_size = obj.m_size;
			m_data = std::make_unique<char[]>(m_size);

			for (int character{ 0 }; character < m_size; character++)
				m_data[character] = obj.m_data[character];

			return *this;
		}

		// Move constructor
		String(String&& data) noexcept
			: m_size{ data.m_size },
			m_data{ std::move(data.m_data) }
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
		int length() const
		{
			return m_size;
		}

		/* PUBLIC MODIFIERS */
		// remove the last character of the string
		String& pop_back()
		{
			m_size--;
			std::unique_ptr<char[]> temp = std::make_unique<char[]>(m_size);

			for (int it{ 0 }; it < m_size; it++)
				temp[it] = m_data[it];

			m_data = std::move(temp);

			return *this;
		}

		// substract a part of the string
		String sub(int start, int end = 0)
		{
			if (end == 0)
				end = m_size;

			if (start < 0 || end > m_size)
				throw std::runtime_error("error, index out of bounds");

			int size = end - start;
			std::unique_ptr<char[]> temp = std::make_unique<char[]>(size);

			for (int it{ 0 }; it < size; it++)
				temp[it] = m_data[start + it];

			return String(temp.get());
		}

		// See sub()
		String substring(int start, int end = 0)
		{
			return sub(start, end);
		}

		// See sub() 
		String cut(int start, int end = 0)
		{
			return sub(start, end);
		}

		// Append character(s) to the end of the string
		String& append(const char* string)
		{
			int size = getSize(string);
			this->m_size += getSize(string);

			std::unique_ptr<char[]> temp = std::make_unique<char[]>(size);

			for (int it{ 0 }; it < this->m_size; it++)
				temp[it] = this->m_data[it];

			for (int it{ 0 }; it < size; it++)
				temp[m_size + it] = string[it];

			this->m_data = std::move(temp);

			return *this;
		}

		// Replace a part of the string with another string
		String& replace(int start, const char* string, int end = 0)
		{
			std::unique_ptr<char[]> temp = std::make_unique<char[]>(this->m_size + getSize(string));

			for (int it{ 0 }; it < start; it++)
				temp[it] = this->m_data[it];

			for (int it{ start }; it < (this->m_size + getSize(string)); it++)
				temp[it] = string[it - start];

			this->m_data = std::move(temp);

			return *this;
		}

		/* OPERATORS OVERLOADS */
		// add more characetrs to the string
		String& operator+=(const char* string)
		{
			return append(string);
		}

		// see pop_back()
		String& operator--()
		{
			return pop_back();
		}

		/* EXTERNS/OVERRIDES */
		// Print out the object
		friend std::ostream& operator<<(std::ostream& out, const String& obj)
		{
			return out << obj.getData();
		}

	private:
		/* PRIVATE GETTERS */
		int getSize(const char* data) const
		{
			return std::count_if(data, data + sizeof(data), [](char c) { return c != '\0'; });
		}
		// Calculate and Returns the number of characters in the string

		// Returns the string
		const char* getData() const
		{
			if (!m_data)
				throw std::runtime_error("error, string is empty");

			return m_data.get();
		}

		/* PRIVATE MODIFIERS */
		// Add a character to the end of the string
		String& push_back(const char character)
		{
			m_size++;
			std::unique_ptr<char[]> temp = std::make_unique<char[]>(m_size);

			for (int it{ 0 }; it < m_size - 1; it++)
				temp[it] = m_data[it];

			temp[m_size - 1] = character;
			m_data = std::move(temp);

			return *this;
		}

	private:
		/* Member variables */
		std::unique_ptr<char[]> m_data;
		int m_size = 0;
	};

	namespace Math
	{
		/* MATH BASIC OPERATIONS */
		// Returns the sum of two numbers
		template <typename T, typename U>
		auto add(T number1, U number2)
		{
			return number1 + number2;
		}

		// Returns the difference of two numbers
		template <typename T, typename U>
		auto sub(T number1, U number2)
		{
			return number1 - number2;
		}

		// Returns the product of two numbers
		template <typename T, typename U>
		auto mul(T number1, U number2)
		{
			return number1 * number2;
		}

		// returns the quotient of two numbers
		template <typename T, typename U>
		auto div(T number1, U number2)
		{
			return number1 / number2;
		}

		// TODO LATER: fix the number of digits after the decimal point later
		// returns the square root of a number
		long double sqrt(long double value)
		{
			if (value < 0)
				return -1;

			long double lo = 1.l;
			long double hi = value;

			while (hi - lo > 0.00001)
			{
				double mid = lo + (hi - lo) / 2.l;
				if (mid * mid - value > 0.00001)
				{
					hi = mid;
				}
				else {
					lo = mid;
				}
			}
			return lo;
		}

		// returns exponents
		int exponent(int number, int power)
		{
			for (int iteration{ 1 }; iteration < power; iteration++)
				number *= number;

			return number;
		}

		/* LIST OF CONSTANTS */
		namespace Constants
		{
			constexpr double PI = 3.14159265358979323846;
			constexpr double EULERS = 2.71828182845904523536;
			constexpr double GOLDEN_RATIO = 1.61803398874989484820;
			constexpr int SPEED_OF_LIGHT = 186282;
		}

		/* VECTORS 2D */
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
			{
			}

			Vector2(T x, U y)
				: m_x{ x }, m_y{ y }
			{
			}

			// Copy constructor
			Vector2(const Vector2& obj)
				: m_x{ obj.m_x }, m_y{ obj.m_y }
			{
			}

			// Copy assignment
			Vector2& operator=(const Vector2& obj)
			{
				if (this == &obj)
					return *this;

				this->m_x = obj.m_x;
				this->m_y = obj.m_y;

				return *this;
			}

			// Move constructor
			Vector2(Vector2&& obj) noexcept
				: m_x{ std::move(obj.m_x) }, m_y{ std::move(obj.m_y) }
			{
				obj.m_x = 0;
				obj.m_y = 0;
			}

			// Move assignment
			Vector2& operator=(Vector2&& obj) noexcept
			{
				if (this == &obj)
					return *this;

				this->m_x = std::move(obj.m_x);
				this->m_y = std::move(obj.m_y);

				obj.m_x = 0;
				obj.m_y = 0;

				return *this;
			}

			// Destructor
			~Vector2() = delete;

			/* OPERATORS OVERLOADS */
			// Returns the sum of two vectors
			Vector2& operator+(const Vector2& obj)
			{
				return Vector2(this->m_x + obj.m_x, this->m_y + obj.m_y);
			}

			Vector2& operator-(const Vector2& obj)
			{
				return Vector2(this->m_x - obj.m_x, this->m_y - obj.m_y);
			}

			// Returns Unit Vector
			Vector2& operator/(int scalar)
			{
				return Vector2(this->m_x / scalar, this->m_y / scalar);
			}

			int operator*(const Vector2& obj)
			{
				return this->m_x * obj.m_x + this->m_y * obj.m_y;
			}

			bool operator==(const Vector2& obj)
			{
				return this->m_x == obj.m_x && this->m_y == obj.m_y;
			}

			bool operator!=(const Vector2& obj)
			{
				return !(this == obj);
			}

			int dotProduct(const Vector2& obj)
			{
				return this * obj;
			}

			int crossProduct(const Vector2& obj)
			{
				return this->m_x * obj.m_y - this->m_y * obj.m_x;
			}

			/* PUBLIC GETTERS */
			// Returns the x member variable
			const U& getX() const noexcept
			{
				return m_x;
			}

			// Returns the y member variable
			const T& getY() const noexcept
			{
				return m_y;
			}

			/* EXTERNS/OVERRIDES */
			// Print out the object
			friend std::ostream& operator<<(std::ostream& out, const Vector2<T, U>& obj)
			{
				out << "( " << obj.m_x << ", " << obj.m_y << ")";
				return out;
			}

		private:
			/* Member variables */
			T m_x{};
			U m_y{};
		};
		template <typename T, typename U>
		using Vec2 = Vector2<T, U>;
	}
}

#endif /* UTILS_H */
