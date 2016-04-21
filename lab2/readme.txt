/**********************************************************************
 *  Knäcka lösenord readme.txt
 **********************************************************************/

 Ungefärligt antal timmar spenderade på labben (valfritt):

För många.

/**********************************************************************
 *  Ge en hšgnivŒbeskrivning av ditt program decrypt.c.
 **********************************************************************/
Först skapas en lista med krypteringsnycklarna från filerna random#.txt.
En loop räknar alla möjliga kombinationer av den högra halvan av ett potentiellt lösenord.
Lägger krypterade värden i en map. Tex för läsen med 8 bokstäver : aaaaaaaa till aaaa5555 (000...000 tillochmed 0000...11111 )
Det sista okrypterade lösenordet sparas i en variabel "firsthalf".
I en annan loop prövas alla kombinationer av den vänstra halvan i lösenordet. I mappen söks ett värde som är lika med "det lösenord som ska knäckas" minus "den krypterade vänsterhalvan". Om värdet finns så läggs nyckeln i en vektor som sedan kan skrivas ut efter körningen.

/**********************************************************************
 *  Beskriv symboltabellen du anvŠnt fšr decrypt.c.
 **********************************************************************/
//Standardbibliotekets Map. Den kontainern brukar vara ett binŠra sšktrŠd av Pairs. Går att göras mer effektiv med unordered_map och en hashfunktion som lägger pairsen någon form av lista.
KOMPLETTERING: Nu använder vi multimapp för att kunna lagra flera lösenord som har samma kryptering. 

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla lösenord med 8 och 10
 *  bokstäver i uppgiften du lyckades knäca med DIN kod.
 **********************************************************************/


8 bokstäver
-----------
(vettiga lösenord)	(skruttiga men giltiga lösenord)	
congrats		ibqfehan
youfound		mqubzd45
theright	
solution		aeiqrsd4


10 bokstäver:
-----------
completely		nbryjimvrd
unbreakabl
cryptogram
ormaybenot




/****************************************************************************
 *  Hur lŒng tid anvŠnder brute.c fšr att knŠcka lšsenord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar lŠngre tid Šn vad
 *  du orkar vŠnta. Ge en kort motivering fšr dina uppskattningar.
 ***************************************************************************/


Char     Brute     
--------------
 4	1 sekund
 5	32 sekunder
 6	1519 sekunder
 8	* 16 timmar 2^(8*5/2) / 2^(6*5/2). 8 tecken borde ta 32 ggr längre tid än 6 tecken


/******************************************************************************
 *  Hur lŒng tid anvŠnder decrypt.c fšr att knŠcka lšsenord av en viss storlek?
 *  Hur mycket minne anvŠnder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar lŠngre tid Šn vad
 *  du orkar vŠnta. Ge en kort motivering fšr dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6	0		hinner inte se
8	4		hinner inte se, ca 50 mb
10	337 		1,52 GB
12	*		Tillräckligt för att en dator med 8gb ram ska flippa ur totalt

/*************************************************************************
 * Hur mŒnga operationer anvŠnder brute.c fšr ett N-bitars lšsenord?
 * Hur mŒnga operationer anvŠnder din decrypt.c fšr ett N-bitars lšsenord?
 * AnvŠnd ordo-notation.
 *************************************************************************/

decrypt: O( (2^N/2) + (2^N/2)*logn)
brute: O( 2^N ))
