#include<iostream>
#include<set>
#include <bits/stdc++.h>

using namespace std;

struct tcp_pair {
    union {
        unsigned int ip; 
        unsigned char oct[4];// 32 bit
    }ip_addr;
    int port;

    tcp_pair(): tcp_pair{0, 0} {};
    tcp_pair(int p, unsigned int address): port{p}, ip_addr{address} {}
};

ostream & operator << (ostream &out,const tcp_pair& c) {
    return out << (int)c.ip_addr.oct[3] << "."
		       << (int)c.ip_addr.oct[2] << "."
			   << (int)c.ip_addr.oct[1] << "."
			   << (int)c.ip_addr.oct[0] << " : " <<c.port;
}

namespace std{

		template<>
		struct hash <tcp_pair>{

			hash(){ cout << "hash<tcp_pair> constructor" << endl; }

			size_t operator()(const tcp_pair& tcp_pair) const {
				cout << "operator HASH: [" << tcp_pair << "]" << endl;
				return tcp_pair.port % 10;
			}
		};

		template<>
		struct equal_to<tcp_pair>{

			equal_to(){ cout << "equal_to<tcp_pair> constructor" << endl; }

			bool operator()(const tcp_pair& p1, const tcp_pair& p2) const { 
				cout << "operator EQUAL: [" << p1 << "," << p2 << "]" << endl;
				return (p1.port == p2.port) && (p1.ip_addr.ip == p2.ip_addr.ip);
			}
		};

};

int main(){

    std::unordered_set <tcp_pair> my_set;

	my_set.insert( {1, 192} );
	my_set.insert( {2, 192} );
	my_set.insert( {3, 192} );
	my_set.insert( {4, 192} );
	/*
	 *my_set.insert( {4, 192} );
	 *my_set.insert( {4, 192} );
	 *my_set.insert( {4,  77} );
	 */
	my_set.insert( {14,  77} );

	cout << "==================== Items: " << endl;
	for(auto &item: my_set)
		cout << item << endl;
}


