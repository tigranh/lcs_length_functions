
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

#include "ml/lcs/cost_function_segments.hpp"
#include "ml/lcs/hirschberg.hpp"


int main()
{
	// Test 1
	{
		std::string s1 = "abbaaabaaba";
		std::string s2 = "bbabbbbaa";
		int length = ml::lcs::cost_function_segments::lcs( 
				s1.begin(), s1.end(), 
				s2.begin(), s2.end() );
		std::cout << "|LCS| of '" << s1 << "' and '" << s2 << "' is " 
				<< length << std::endl;
	}
	
	// Test 2
	{
		int a1[] = { 1, 2, 1, 1, 3, 3, 1, 3, 4, 2, 4 };
		int a1_size = sizeof(a1) / sizeof(a1[0]);
		int a2[] = { 2, 1, 3, 1, 4, 4, 1, 1, 2, 2, 4 };
		int a2_size = sizeof(a2) / sizeof(a2[0]);
		int length = ml::lcs::cost_function_segments::lcs( 
				a1, a1 + a1_size, 
				a2, a2 + a2_size );
		std::cout << "|LCS| of the 2 integers sequences is " 
				<< length << std::endl;
	}
	
	// Test 3
	{
		std::string s1 = "ctagctaagctcgattcca";
		std::string s2 = "cgatatatgcgtaatagag";
		std::vector< int > prefixes_length;
		ml::lcs::cost_function_segments::lcs_prefixes( 
				s1.begin(), s1.end(), 
				s2.begin(), s2.end(), 
				std::back_inserter( prefixes_length ) );
		std::cout << "|LCS| of all prefixes of '" << s1 << "' and of '" 
				<< s2 << "' are: "
				<< std::endl;
		for ( int i = 0; i < (int)prefixes_length.size(); ++i )
			std::cout << " " << prefixes_length[ i ];
		std::cout << std::endl;
	}
	
	// Test 4
	{
		std::string s1 = "ctagctaagctcgattcca";
		std::string s2 = "cgatatatgcgtaatagag";
		std::vector< std::string::iterator > p1, p2;
		int length = ml::lcs::hirschberg::lcs_path( 
				s1.begin(), s1.end(), 
				s2.begin(), s2.end(), 
				std::back_inserter( p1 ), 
				std::back_inserter( p2 ), 
				ml::lcs::cost_function_segments::lcs_prefixes, 
				ml::lcs::cost_function_segments::lcs_prefixes );
		std::cout << "An LCS of '" << s1 << "' and '" << s2 << "' is: ";
		for ( int i = 0; i < length; ++i )
			std::cout << *(p1[ i ]);
		std::cout << std::endl;
	}
	
	return 0;
}
