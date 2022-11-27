Autentificarea reprezinta procesul prin care se verifica daca un user este cine declara ca este (de exemplu in laboratorul actual,
oricine poate declara ca este user/admin, dar doar dupa verificarea credentialelor se va "autentifica" persoana respectiva)).
Verificarea credentialelor poate fi de tipul match-uirea userului cu parola aferenta, a datelor biometrice (scan amprenta, iris),
a unui PIN sau a unei simple parole.

In timp ce autentificare reprezinta acest proces de verificare, login-ul reprezinta efectiv setul de credentiale (date biometrice, user, parola, PIN etc.)
si instantierea unei sesiuni de login in care utilizatorul respectiv are anumite drepturi si este "autorizat" sa faca anumite lucruri, in conformitate cu profilul sau.

Exista diverse tipuri de login, folosite pentru ca utilizatorii sau companiile sa isi securizeze datele.
Acestea includ login in sistemul de operare, login pe un website, login intr-o aplicatie etc.

Asadar, autentificarea si login-ul sunt doua procese diferite.

Autorizarea reprezinta procesul prin care un anumit utilizator primeste anumite drepturi de a folosi in diverse feluri anumite date din baza de date.
Exista diversi factori de autorizare pe care companiile in general le folosesc pentru a-si autentifica utilizatorii.
Acestia includ knowledge factor, possession, inherence, location, time factors etc.
Exista ACL-uri (Acces Control Lists) care indica drepturile fiecarui utilizator.

In mod normal, login-ul se realizeaza in felul urmator:

Deschid aplicatia => imi apare fereastra/pagina de login (sau intru in aceasta de pe pagina home aparuta initial) =>
Introduc credentialele (de obicei username si parola) => se instantiaza o sesiune de login in care am fost autentificat drept
utilizatorul pe care imi doream sa il accesez => Acum am drepturile (sunt autorizat sa) de a face anumite lucruri =>
Cand ne dorim sa oprim sesiunea de login apasam butonul de delogare

Posibile metode extra de securitate :
1) Pastrarea soft-urilor up to date
2) Folosirea programelor antivirus si firewall
3) Folosirea unor parole puternice si a unui tool de management al parolelor (ex : LastPass)
4) Utilizarea autentificare in 2 sau mai multi pasi
5) Backup-uirea frecventa a datelor
6) Evitarea wi-fi - urilor publice sau cu parole cunoscute de oricine
