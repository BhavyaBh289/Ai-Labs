male(bhavya).
male(nishant).
male(shrut).
male(shrey).
male(hemang).
male(prashant).
male(rikhav).
male(gaurang).
male(bhavin).
male(dineshbhai).
male(chandrakant).



female(preksha).
female(maitri).
female(bhavi).
female(kinjal).
female(hemali).
female(sapnaben).
female(neepa).
female(krisha).
female(dhara).
female(chandrika).


parent( maitri,preksha).
parent( nishant,preksha).
parent( maitri,bhavya).
parent( nishant,bhavya).
parent( chandrakant,nishant).
parent( sapnaben,nishant).
parent( dineshbhai,maitri).
parent( chandrika,maitri).
parent( kinjal,shrey).
parent( hemang,shrey).
parent( kinjal,shrut).
parent( hemang,shrut).
parent( chandrakant,hemang).
parent( sapnaben,hemang).
parent( prashant,bhavi).
parent( hemali,bhavi).
parent( sapnaben,hemali).
parent( chandrakant,hemali).
parent( gaurang,rikhav).
parent( neepa,rikhav).
parent( dineshbhai,gaurang).
parent( chandrika,gaurang).
parent( bhavin,krisha).
parent( dhara,krisha).
parent( dineshbhai,bhavin).
parent( chandrika,bhavin).


father(X, Y) :- male(X), parent(X, Y).

mother(X, Y) :- female(X), parent(X, Y).

wife(X,Y) :- parent(X,Z),parent(Y,Z).

father_in_law(X, Y) :- male(X),female(Y),parent(Y,T),grandfather(X,T).

mother_in_law(X, Y) :- female(X),female(Y),parent(Y,T),grandmother(X,T).

son(X, Y) :- male(X), parent(Y, X).

daughter(X, Y) :- female(X), parent(Y, X).

grandfather(X, Z) :- father(X, Y), parent(Y, Z).

brother_in_law(X,Y) :- male(W),male(X),sibling(X,W),father(W,T),mother(Y,T).

sister_in_law(X,Y) :- female(X),sibling(X,Z),wife(Z,W),sibling(W,Y).

grandmother(X, Z) :- mother(X, Y), parent(Y, Z).

sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.

cousin(X, Y) :- parent(Z, X), parent(W, Y), sibling(Z, W).

uncle(X, Y) :- parent(Z, Y), sibling(X, Z), male(X).

aunt(X, Y) :- cousin(Z, Y), mother(X, Z), female(X).

second_uncle(X, Y) :-male(X),grandfather(W, Y), sibling(W,Z),son(X,Z).

second_aunt(X, Y) :-female(X),grandfather(W, Y), sibling(W,Z),grandfather(Z,D),mother(X,D).

second_cousin(X, Y) :- grandfather(W, Y), sibling(W,Z),grandfather(Z,X).

second_grandfather(X,Y) :- grandfather(W,Y),sibling(W,X).

second_grandmother(X,Y) :- second_uncle(W,Y),mother(X,W).



% Your family relationships and rules here
find_relationship(X, Y) :-
    father(X, Y), write(X), write(' is the father of '), write(Y), nl.

find_relationship(X, Y) :-
    wife(X, Y), write(X), write(' is the wife of '), write(Y), nl.

find_relationship(X, Y) :-
    mother(X, Y), write(X), write(' is the mother of '), write(Y), nl.

find_relationship(X, Y) :-
    son(X, Y), write(X), write(' is the son of '), write(Y), nl.

find_relationship(X, Y) :-
    daughter(X, Y), write(X), write(' is the daughter of '), write(Y), nl.

find_relationship(X, Y) :-
    grandfather(X, Y), write(X), write(' is the grandfather of '), write(Y), nl.

find_relationship(X, Y) :-
    sibling(X, Y), write(X), write(' is the sibling of '), write(Y), nl.

find_relationship(X, Y) :-
    father(Z, Y), mother(X, Z), write(X), write(' is the grandmother of '), write(Y), nl.

find_relationship(X, Y) :-
    second_grandmother(X,Y), write(X), write(' is the second grandmother of '), write(Y), nl.

find_relationship(X, Y) :-
    second_grandfather(X,Y), write(X), write(' is the second grandfather of '), write(Y), nl.

find_relationship(X, Y) :-
    second_uncle(X, Y), write(X), write(' is the second-uncle of '), write(Y), nl.

find_relationship(X, Y) :-
    second_aunt(X, Y), write(X), write(' is the second-aunt of '), write(Y), nl.

find_relationship(X, Y) :-
    uncle(X, Y), write(X), write(' is the uncle of '), write(Y), nl.

find_relationship(X, Y) :-
    aunt(X, Y), write(X), write(' is the aunt of '), write(Y), nl.

find_relationship(X, Y) :-
    cousin(X, Y), write(X), write(' is the cousin of '), write(Y), nl.

find_relationship(X, Y) :-
    sister_in_law(X, Y), write(X), write(' is the sister in law of '), write(Y), nl.

find_relationship(X, Y) :-
    brother_in_law(X, Y), write(X), write(' is the brother_in_law of '), write(Y), nl.

find_relationship(X, Y) :-
    second_cousin(X, Y), write(X), write(' is the second cousin of '), write(Y), nl.

find_relationship(X, Y) :-
    father_in_law(X, Y), write(X), write(' is the father-in-law of '), write(Y), nl.

find_relationship(X, Y) :-
    mother_in_law(X, Y), write(X), write(' is the mother-in-law of '), write(Y), nl.

find_relationship(X, Y) :- write('Relationship not defined between '), write(X), write(' and '), write(Y), nl.

