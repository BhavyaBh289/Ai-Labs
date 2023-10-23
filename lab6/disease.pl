% Define symptoms and diseases
symptom(feeling_feverish).
symptom(cough).
symptom(runny_nose).
symptom(sore_throat).
symptom(headache).
symptom(body_aches).

disease(flu).
disease(cold).
disease(allergies).

% Define rules for diagnosis
diagnose(Disease) :-
    symptom(feeling_feverish),
    symptom(cough),
    symptom(body_aches),
    symptom(headache),
    Disease = flu.

diagnose(Disease) :-
    symptom(runny_nose),
    symptom(sore_throat),
    Disease = cold.

diagnose(Disease) :-
    symptom(runny_nose),
    symptom(sore_throat),
    symptom(cough),
    Disease = allergies.

% Main querying predicate
expert_diagnosis(Disease) :-
    write('Please enter your symptoms (one at a time, finish with "done"): '), nl,
    read_symptoms(Symptoms),
    diagnose(Disease).

% Predicate for reading symptoms
read_symptoms([]) :- !.
read_symptoms([Symptom | Rest]) :-
    read(Symptom),
    read_symptoms(Rest).

% Entry point
start_diagnosis :-
    expert_diagnosis(Disease),
    write('You may have: '), write(Disease), nl,
    write('Please consult a healthcare professional for confirmation.'), nl.

% Run the expert system
:- start_diagnosis.

