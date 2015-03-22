#ifndef __EXTEND_STL_STRING_ALGORITHM_HPP
#define __EXTEND_STL_STRING_ALGORITHM_HPP

/** @algorithm.hpp
*
* @author <����>
* [@author <chenyu2202863@yahoo.com.cn>]
* @date <2012/10/08>
* @version <0.1>
*
* �ַ��������㷨
*/


#include <iomanip>
#include <algorithm>
#include <functional>
#include <type_traits>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include <cctype>

/*
��Сдת��
	to_upper
	to_lower
	to_number
	to_string

�Ե��ո�
	trim_left
	trim_right
	trim

ɾ��
	erase

���ִ�Сд�Ƚ�
	compare_no_case

ƥ�����
	find_nocase

��ʼ������ƥ��
	is_start_with
	is_end_with

�ָ�
	split


*/


namespace stdex
{
	namespace detail
	{
		template < typename CharT, typename FuncT >
		struct ret_helper_t
		{
			std::basic_string<CharT> &str_;
			FuncT &func_;
			ret_helper_t(std::basic_string<CharT> &str, FuncT &func)
				: str_(str)
				, func_(func)
			{}

			operator std::basic_string<CharT> &()
			{
				std::transform(str_.begin(), str_.end(), str_.begin(), func_);

				return str_;
			}

			operator size_t() const
			{
				std::transform(str_.begin(), str_.end(), str_.begin(), func_);
				return str_.length();
			}
		};
	}


	/**
	* @brief �ַ���������ĸתΪ��д��֧��char��wchar_t
	* @param <str> <string�ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <�����ڸ��ݽ���������ʽת��>
	* @note <�������Ƶ��ַ�����char or wchar_t>
	* @remarks <ת�������ַ��������ַ�Ϊ��д>
	*/
	template < typename CharT >
	void to_upper(std::basic_string<CharT> &&str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
	}
	
	template < typename CharT >
	detail::ret_helper_t<CharT, decltype(::toupper)> to_upper(const std::basic_string<CharT> &str)
	{
		return detail::ret_helper_t<CharT, decltype(::toupper)>(const_cast<std::basic_string<CharT> &>(str), ::toupper);
	}

	// ֧���ַ�������
	template < typename CharT, size_t N >
	inline void to_upper(CharT (&str)[N])
	{
		std::transform(str, str + N, str, ::toupper);
	}


	/**
	* @brief �ַ���������ĸתΪСд��֧��char��wchar_t
	* @param <str> <string�ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <�����ڸ��ݽ���������ʽת��>
	* @note <�������Ƶ��ַ�����char or wchar_t>
	* @remarks <ת�������ַ��������ַ�ΪСд>
	*/
	template < typename CharT >
	void to_lower(std::basic_string<CharT> &&str)
	{
		std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	}

    template < typename CharT >
    detail::ret_helper_t<CharT, decltype(::tolower)> to_lower(const std::basic_string<CharT> &str)
    {
        return detail::ret_helper_t<CharT, decltype(::tolower)>(const_cast<std::basic_string<CharT> &>(str), ::tolower);
    }

	// ֧���ַ�������
	template < typename CharT, size_t N >
	inline void to_lower(CharT (&str)[N])
	{
		std::transform(str, str + N, str, ::tolower);
	}


	namespace detail
	{
		template < typename CharT >
		struct to_number_helper_t
		{
			std::basic_istringstream<CharT> is_;

			to_number_helper_t(const std::basic_string<CharT> &str)
				: is_(str)
			{}

			template < typename T >
			operator T()
			{
				static_assert(std::is_integral<T>::value || 
					std::is_enum<T>::value ||
					std::is_floating_point<T>::value, "T must is a number");

				T val = 0;
				is_ >> val;
				return val;
			}

			operator bool()
			{
				bool val = false;
				is_ >> std::boolalpha >> val;
				return val;
			}
		};
	}

	

	/**
	* @brief ���ַ���תΪnumber��bool��֧��char��wchar_t
	* @param <str> <string�ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <�����ڸ��ݽ���������ʽת��>
	* @note <�������Ƶ��ַ�����char or wchar_t>
	* @remarks <ת�������ַ���Ϊnumber����bool����>
	*/
	template < typename CharT >
	inline detail::to_number_helper_t<CharT> to_number(const std::basic_string<CharT> &str)
	{
		return detail::to_number_helper_t<CharT>(str);
	}

	template < typename CharT >
	inline detail::to_number_helper_t<CharT> to_number(const CharT *str)
	{
		std::basic_string<CharT> val(str);
		return detail::to_number_helper_t<CharT>(val);
	}


	
	namespace detail
	{
		template < typename T >
		struct to_string_helper_t
		{
			T val_;
			int prec_;
			bool is_boolalpha_;

			to_string_helper_t(const T &val, int prec = 0, bool is_boolalpha = false)
				: val_(val)
				, prec_(prec)
				, is_boolalpha_(is_boolalpha)
			{
				static_assert(std::is_integral<T>::value || 
					std::is_enum<T>::value ||
					std::is_floating_point<T>::value, "T must is a number");

				if( prec_ != 0 )
					assert(is_boolalpha == false);
			}

			template < typename CharT >
			operator std::basic_string<CharT>() const
			{
				std::basic_ostringstream<CharT> os;
				if( prec_ != 0 )
					os << std::setiosflags(std::ios::fixed) << std::setprecision(prec_);
				if( is_boolalpha_ )
					os << std::boolalpha;

				os << val_;

				assert(os.good() || os.eof());
				return os.str();
			}
		};
	}

	/**
	* @brief ��number��boolתΪ�ַ�����֧��char��wchar_t
	* @param <val> <valΪnumber��bool>
	* @exception <�����׳��κ��쳣>
	* @return <�����ڸ��ݽ���������ʽת��Ϊstd::string��std::wstring>
	* @note <�������Ƶ�����������ͣ�������Ϊnumer��bool>
	* @remarks <>
	*/
	template < typename T >
	inline detail::to_string_helper_t<T> to_string(const T &val)
	{
		return detail::to_string_helper_t<T>(val);
	}

	template < typename T >
	inline detail::to_string_helper_t<T> to_string(const T &val, int prec)
	{
		return detail::to_string_helper_t<T>(val, prec);
	}

	inline detail::to_string_helper_t<bool> to_string(bool val)
	{
		return detail::to_string_helper_t<bool>(val, 0, true);
	}



	/**
	* @brief �ַ����滻��֧��char��wchar_t
	* @param <str> <��Ҫ�滻���ַ���>
	* @param <old_value> <���滻��ƥ���ַ���>
	* @param <new_value> <�����滻���ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <�����滻����ַ���>
	* @note <�������Ƶ������������>
	* @remarks <>
	*/
	template < typename CharT >
	std::basic_string<CharT> &replace_all(std::basic_string<CharT> &str, const std::basic_string<CharT> &old_value, const std::basic_string<CharT> &new_value)     
	{     
		while(true)   
		{     
			std::basic_string<CharT>::size_type pos(0);     
			if( ( pos = str.find(old_value)) != std::basic_string<CharT>::npos )     
				str.replace(pos, old_value.length(), new_value);     
			else   
				break;     
		}     
		return str;     
	}     

	
	/**
	* @brief ɾ���ַ������ȫ���ո�֧��char��wchar_t
	* @param <str> <�ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <��>
	* @note <�������Ƶ������������>
	* @remarks <>
	*/
	template< typename CharT >
	inline void trim_left(std::basic_string<CharT> &str)
	{
		str.erase(0, str.find_first_not_of(' '));
	}


	/**
	* @brief ɾ���ַ����ұ�ȫ���ո�֧��char��wchar_t
	* @param <str> <�ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <��>
	* @note <�������Ƶ������������>
	* @remarks <��>
	*/
	template< typename CharT >
	inline void trim_right(std::basic_string<CharT> &str)
	{
		str.erase(str.find_last_not_of(' ') + 1);
	}


	/**
	* @brief ɾ���ַ�����������ȫ���ո�֧��char��wchar_t
	* @param <str> <�ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <��>
	* @note <�������Ƶ������������>
	* @remarks <��>
	*/
	template< typename CharT >
	inline void trim(std::basic_string<CharT> &str)
	{
		str.erase(0, str.find_first_not_of(' '));
		str.erase(str.find_last_not_of(' ') + 1);
	}

	/**
	* @brief ɾ���ַ���������ָ���ַ���֧��char��wchar_t
	* @param <str> <���ô�����Ҫɾ�����ַ���>
	* @param <charactor> <��Ҫɾ�����ַ�>
	* @exception <�����׳��κ��쳣>
	* @return <��>
	* @note <�������Ƶ������������>
	* @remarks <��>
	*/	
	template < typename CharT >
	inline void erase(std::basic_string<CharT> &str, const CharT &charactor)
	{
		str.erase(std::remove_if(str.begin(), str.end(), 
			std::bind2nd(std::equal_to<CharT>(), charactor)), str.end());
	}


	/**
	* @brief �ж��ַ����Ƿ���ָ���ַ�����ͷ��֧��char��wchar_t
	* @param <str> <��Ҫ�жϵ��ַ���>
	* @param <src> <�����жϱ�׼���ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <�����str����srcΪ��ͷ���򷵻�true�����򷵻�false>
	* @note <�������Ƶ������������>
	* @remarks <��>
	*/	
	template < typename CharT >
	inline bool is_start_with(const std::basic_string<CharT> &str, const std::basic_string<CharT> &src)
	{
		return str.compare(0, src.size(), src) == 0;
	}


	/**
	* @brief �ж��ַ����Ƿ���ָ���ַ�����β��֧��char��wchar_t
	* @param <str> <��Ҫ�жϵ��ַ���>
	* @param <src> <�����жϱ�׼���ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <�����str����srcΪ��β���򷵻�true�����򷵻�false>
	* @note <�������Ƶ������������>
	* @remarks <��>
	*/
	template < typename CharT >
	inline bool is_end_with(const std::basic_string<CharT> &str, const std::basic_string<CharT> &src)
	{
		return str.compare(str.size() - src.size(), src.size(), src) == 0;
	}


	/**
	* @brief ���Դ�Сд�����ַ����Ƿ���Ŀ���ַ����д��ڣ�֧��char��wchar_t
	* @param <str> <��Ҫ�жϵ��ַ���>
	* @param <val> <��Ҫ���ҵ��ַ����ַ���>
	* @exception <�����׳��κ��쳣>
	* @return <����ҵ��򷵻�true�����򷵻�false>
	* @note <�������Ƶ������������>
	* @remarks <��>
	*/
	template < typename CharT >
	inline bool find_nocase(const std::basic_string<CharT> &str, const std::basic_string<CharT> &val)
	{
		auto iter = std::search(str.begin(), str.end(), val.begin(), val.end(), 
			[](CharT lhs, CharT rhs) { return ::tolower(lhs) == ::tolower(rhs); });
		return iter != str.end();
	}

	
	/**
	* @brief ��ָ���ַ��ָ��ַ�����֧��char��wchar_t
	* @param <seq> <�ָ����ַ�������>
	* @param <str> <��Ҫ�ָ���ַ���>
	* @param <separator> <���Էָ���ַ�>
	* @exception <�����׳��κ��쳣>
	* @return <��>
	* @note <�������Ƶ������������>
	* @remarks <�ָ�ɹ����ַ�������vector�з���>
	*/
	template < typename ValueType, typename CharT >
    inline void split(std::vector<ValueType> &seq, const std::basic_string<CharT> &str, CharT separator)
	{
		if( str.empty() )
			return;

		std::basic_istringstream<CharT> iss(str);
		for(std::basic_string<CharT> s; std::getline(iss, s, separator); )
		{
            ValueType val;
			std::basic_istringstream<CharT> isss(s);

			isss >> val;

			assert(isss.good() || isss.eof());
			seq.push_back(std::move(val));
		}

		return;
	}

	/**
	* @brief ��ָ���ַ��ָ��ַ���������ָ��λ�õ��ַ�����֧��char��wchar_t
	* @param <str> <��Ҫ�ָ���ַ���>
	* @param <separator> <���Էָ���ַ�>
	* @param <index> <�ָ����ַ���λ�ã��±�0��ͷ>
	* @exception <out_of_range>
	* @return <����ָ���±��ַ���������±�Խ�磬���׳��쳣out_of_range>
	* @note <�������Ƶ������������>
	* @remarks <�ָ�ɹ����ַ�������vector�з���>
	*/
	template < typename CharT >
	inline std::basic_string<CharT> split(const std::basic_string<CharT> &str, CharT separator, size_t index)
	{
		std::vector<std::basic_string<CharT>> seq;
		split(seq, str, separator);

		if( seq.empty() )
			return std::basic_string<CharT>();

		assert(index < seq.size());
		if( index >= seq.size() )
		{			
			return std::basic_string<CharT>();
		}
		
		return seq[index];
	}


}


#endif