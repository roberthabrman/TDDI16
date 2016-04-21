	multimap<Key, Key> mappen_1;

	firstcandidate = candidate;
	++firstcandidate;

// lägger alla möjliga låga halvor i en map. För lösen med 8 bokstäver : aaaaaaaa till aaaa5555 (000...000 tillochmed 0000...11111 )
	do
	{
		//cout << endl << candidate << " till mapp_1, första halvan" << endl;
		candenc = KEYsubsetsum(candidate, T);

		//mappen_1.insert ( std::pair<Key, Key>(candidate, candenc) );
		mappen_1.insert ( std::pair<Key, Key>(candenc, candidate) );
		++candidate;
	}
//	while (KEYbit(candidate, B*(C/2) +10) == 0); // högerkandidater
	while (KEYbit(candidate, B * (C / 2) - 1) == 0); // högerkandidater

	Key firsthalf = candidate; // sparar undan sista värdet så vi vet hur mycket vi ska öka andra halvan med.


	do
	{
		//cout << endl << candidate << " till mapp_1, andra halvan" << endl;
		candenc = KEYsubsetsum(candidate, T);


// Multinmaps fantastiska equal_range-funktion returnerar ett spann med iteratorer till de funna nyckel/värdenparen
		pair <multimap<Key, Key>::iterator, multimap<Key, Key>::iterator> ret;
		ret = mappen_1.equal_range(encrypted - candenc); // söker i mappen. Det krypterade riktiga lösenordet minus kandidaten i vänsterhalvan.

		for (std::multimap<Key, Key>::iterator it = ret.first; it != ret.second; ++it)
			std::cout << " " << it->second + candidate << endl;

		candidate = candidate + firsthalf; // Uppar candidate till nästa bokstav (vänstra halvan alltså)
	}
	while (candidate != firsthalf); // kör slut på kandidaterna

	auto end = chrono::high_resolution_clock::now();
	cout << "Decryption took "
	     << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
	     << " seconds." << endl;

