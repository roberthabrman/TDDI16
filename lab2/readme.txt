/**********************************************************************
 *  Kn�cka l�senord readme.txt
 **********************************************************************/

 Ungef�rligt antal timmar spenderade p� labben (valfritt):

F�r m�nga.

/**********************************************************************
 *  Ge en h�gniv�beskrivning av ditt program decrypt.c.
 **********************************************************************/
F�rst skapas en lista med krypteringsnycklarna fr�n filerna random#.txt.
En loop r�knar alla m�jliga kombinationer av den h�gra halvan av ett potentiellt l�senord.
L�gger krypterade v�rden i en map. Tex f�r l�sen med 8 bokst�ver : aaaaaaaa till aaaa5555 (000...000 tillochmed 0000...11111 )
Det sista okrypterade l�senordet sparas i en variabel "firsthalf".
I en annan loop pr�vas alla kombinationer av den v�nstra halvan i l�senordet. I mappen s�ks ett v�rde som �r lika med "det l�senord som ska kn�ckas" minus "den krypterade v�nsterhalvan". Om v�rdet finns s� l�ggs nyckeln i en vektor som sedan kan skrivas ut efter k�rningen.

/**********************************************************************
 *  Beskriv symboltabellen du anv�nt f�r decrypt.c.
 **********************************************************************/
//Standardbibliotekets Map. Den kontainern brukar vara ett bin�ra s�ktr�d av Pairs. G�r att g�ras mer effektiv med unordered_map och en hashfunktion som l�gger pairsen n�gon form av lista.
KOMPLETTERING: Nu anv�nder vi multimapp f�r att kunna lagra flera l�senord som har samma kryptering. 

/**********************************************************************
 *  Ge de dekrypterade versionerna av alla l�senord med 8 och 10
 *  bokst�ver i uppgiften du lyckades kn�ca med DIN kod.
 **********************************************************************/


8 bokst�ver
-----------
(vettiga l�senord)	(skruttiga men giltiga l�senord)	
congrats		ibqfehan
youfound		mqubzd45
theright	
solution		aeiqrsd4


10 bokst�ver:
-----------
completely		nbryjimvrd
unbreakabl
cryptogram
ormaybenot




/****************************************************************************
 *  Hur l�ng tid anv�nder brute.c f�r att kn�cka l�senord av en viss storlek?
 *  Ge en uppskattning markerad med en asterisk om det tar l�ngre tid �n vad
 *  du orkar v�nta. Ge en kort motivering f�r dina uppskattningar.
 ***************************************************************************/


Char     Brute     
--------------
 4	1 sekund
 5	32 sekunder
 6	1519 sekunder
 8	* 16 timmar 2^(8*5/2) / 2^(6*5/2). 8 tecken borde ta 32 ggr l�ngre tid �n 6 tecken


/******************************************************************************
 *  Hur l�ng tid anv�nder decrypt.c f�r att kn�cka l�senord av en viss storlek?
 *  Hur mycket minne anv�nder programmet?
 *  Ge en uppskattning markerad med en asterisk om det tar l�ngre tid �n vad
 *  du orkar v�nta. Ge en kort motivering f�r dina uppskattningar.
 ******************************************************************************/

Char    Tid (sekunder)    Minne (bytes)
----------------------------------------
6	0		hinner inte se
8	4		hinner inte se, ca 50 mb
10	337 		1,52 GB
12	*		Tillr�ckligt f�r att en dator med 8gb ram ska flippa ur totalt

/*************************************************************************
 * Hur m�nga operationer anv�nder brute.c f�r ett N-bitars l�senord?
 * Hur m�nga operationer anv�nder din decrypt.c f�r ett N-bitars l�senord?
 * Anv�nd ordo-notation.
 *************************************************************************/

decrypt: O( (2^N/2) + (2^N/2)*logn)
brute: O( 2^N ))
