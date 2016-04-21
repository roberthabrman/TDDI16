#include <iostream>
#include <chrono>
#include "Key.h"

#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>

#define U B*(C/2)

using namespace std;

int
main(int argc, char* argv[])
{
	unsigned char buffer[C + 1];   // temporary string buffer
	Key candidate = {{0}};         // a password candidate
	Key encrypted;                 // the encrypted password
	Key candenc;                   // the encrypted password candidate
	Key zero = {{0}};              // the all zero key

	Key T[N];                    // the table T
	Key S[N];                    // the table T

	if (argc != 2)
	{
		cout << "Usage:" << endl << argv[0] << " password < rand8.txt" << endl;
		return 1;
	}

	encrypted = KEYinit((unsigned char *) argv[1]);

	// read in table T
	for (int i{0}; i < N; ++i)
	{
		scanf("%s", buffer);// vf ger denna oss en varning men den inte ger en varning i encrypt


		T[i] = KEYinit(buffer);

		/*
				if (i < (N / 2) - 1)
				{
					T[i] = KEYinit(buffer);
				}
				else
					S[i - N / 2 -1] = KEYinit(buffer);

		*/
	}

	auto begin = chrono::high_resolution_clock::now();

//NYA GREJERERERR
//MAPLISTA

	map<Key, Key> mappen_1;

	do
	{
		//cout << endl << candidate << " till mapp_1, första halvan" << endl;
		candenc = KEYsubsetsum(candidate, T);
		//mappen_1.insert ( std::pair<Key, Key>(candidate, candenc) );
		mappen_1.insert ( std::pair<Key, Key>(candenc, candidate) );
		++candidate;
	}
	while (KEYbit(candidate, U - 1) == 0); // kör slut på kandidaterna

	Key firsthalf = candidate;
	cout << endl << endl;
	cout << firsthalf << endl;

	Key testoffer = candidate;
	//vector <pair<Key, Key>>::iterator> resultat;
	do
	{
		//cout << endl << candidate << " till mapp_1, andra halvan" << endl;
		candenc = KEYsubsetsum(candidate, T);
		//mappen_1.insert ( std::pair<Key, Key>(candidate, candenc) );

		auto it = mappen_1.find(encrypted - candenc);

		if (it != mappen_1.end() )
		{
//			resultat.push_back(it);
			cout << "YYEEEAAAHHH " << it->second+candidate << endl;
		}

		candidate = candidate + firsthalf;

	}
	while (candidate != firsthalf); // kör slut på kandidaterna

	cout << "klart: " << endl;
	cout << "haxxat1first : " << mappen_1.find(encrypted)->first << endl;
	cout << "haxxat1second: " << mappen_1.find(encrypted)->second << endl;
//cout << "haxxat2first : " << mappen_2.find(encrypted)->first << endl;
//cout << "haxxat2second: " << mappen_2.find(encrypted)->second << endl;
	cout << "facit        :  " << encrypted << endl;

	cout << endl << endl;

	cout << endl << endl;
	cout << firsthalf << endl;
	//cout << resultat.at(0);




	auto end = chrono::high_resolution_clock::now();
	cout << "Decryption took "
	     << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
	     << " seconds." << endl;

	return 0;
}