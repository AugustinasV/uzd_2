# uzd_2
v1.1  
========================  

Programa sugeneruoja studentų txt failą, kiekvieną eilutę iš sugeneruoto failo irašo kaip string'ą į "lineread" string vektorių.

Sukuriamas Student class'ių vektorius, kiekvienam Student objektui priskiriamas string'as iš "lineread"; string'as išskaidomas į Student class'ės kintamiuosius (vardas, pavardė, nd_paz, egz_paz).  
Apskaičiuojamas galutinis_paz; studentai irašomi į du failus priklausomai nuo pažymio. Pirklausomai nuo pažymio, studentai įrašomi į naują Student class'ės vektorių ir ištrinami iš senojo vektoriaus.  

const int columncount - nustato, iš kiek stulpelių sugeneruoti failą (mažiausias galimas - 4).  
const int size - nustato, iš kiek eilučių (t.y studentų) sugeneruoti failą.  
nd_paz - int vektorius iš (columncount - 3) skaičių.  

v1.1 greičio testavimas (8 stulpeliai)  
---------------------------  
eilučių kiekis failo pavadinime ".txt"  

**class ir struct greičių palyginimas**
| Class        | Struct           | 
| ------------- |-------------| 
| 100000.txt generation: 0.129223s    |100000.txt generation: 0.131175s | 
| 100000.txt handle: 0.245692s        |100000.txt handle: 0.173899s   | 
| 100000.txt sort + write: 0.239032s  |100000.txt sort + write: 0.227268s   | 
| 100000.txt total: 0.614006s         |100000.txt total: 0.532404s           |
|  |  | 
| 1000000.txt generation: 1.37795s | 1000000.txt generation: 1.38576s |
| 1000000.txt handle: 2.4757s| 1000000.txt handle: 1.69626s |
| 1000000.txt sort + write: 2.22162s| 1000000.txt sort + write: 2.22558s |
| 1000000.txt total: 6.07539s| 1000000.txt total: 5.30772s |

**class greičio palyginimas, priklausomai nuo kompiliatoriaus optimizavimo lygio**
| O0   |     O1      |  O2 |  O3    |
| ------------- |-------------| -----| -----|
| 1000000.txt generation: 1.36537s | 1000000.txt generation: 1.00151s |1000000.txt generation: 0.988397s | 1000000.txt generation: 0.96449s |
| 1000000.txt handle: 2.39874s | 1000000.txt handle: 1.20593s | 1000000.txt handle: 1.137s | 1000000.txt handle: 1.05531s|
| 1000000.txt sort + write: 2.26775s | 1000000.txt sort + write: 1.74218s | 1000000.txt sort + write: 1.74841s | 1000000.txt sort + write: 1.74016s|
| 1000000.txt total: 6.03193s | 1000000.txt total: 3.94976s | 1000000.txt total: 3.87391s | 1000000.txt total: 3.76008s|
| 130,3 kB |49,1 kB | 53,2 kB | 57,2 kB |

v1.2  
========================  
v1.1 versija papildytas destruktoriumi, copy konstruktoriumi, copy priskirimo operatoriumi.  

v1.5  
========================  
Klasė Student dabar yra paveldėta iš abstrakčios klasės Person.  

v2.0
========================  
Sukurti versijos v1.5 Unit Testai 
