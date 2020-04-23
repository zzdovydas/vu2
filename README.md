# 1.1v uzduoties ataskaita

1.1v versijoje pakeitus strukturą į klasę, buvo pastebeti keli pakitimai:

* Skaitymo laikas ir įrašymas į vector konteinerį pailgėjo (0.5-0.75s)
* Algoritmo paskirstančio studentus į dvi kategorijas vykdymo laikas neparodė didelių pakitimų.

Naudojant skirtingas kompiliatoriaus optimizavimo funkcijas (O1, O2, O3) pastebėta:


* O1 veikė lėčiau nei O2 ar O3. Skirtumas buvo pastebėtas failo skaityme ir irašyme į vector konteinerį
* O2 ir O3 optimizacijose nebuvo pastebėtas didelis skirtumas, tačiau O3 veikė šiek tiek greičiau.
