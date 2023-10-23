% Define the knowledge base with crop attributes
crop(wheat, loam, temperate, moderate).
crop(rice, clay, tropical, high).
crop(corn, sandy_loam, temperate, moderate).
crop(cotton, loamy_sand, subtropical, high).
crop(soybeans, clay_loam, temperate, low).
crop(sorghum, sandy, subtropical, low).
crop(potatoes, loam, temperate, moderate).
crop(coffee, loamy_sand, tropical, high).
crop(tea, clay, subtropical, high).
crop(sugarcane, sandy_loam, tropical, high).

% Function to suggest suitable crops based on soil type, climate, and precipitation
suggest_crops(Soil, Climate, Rainfall, Crops) :-
    findall(Crop, (crop(Crop, SoilType, ClimateType, RainfallType),
                    suitable_soil(Soil, SoilType),
                    suitable_climate(Climate, ClimateType),
                    suitable_rainfall(Rainfall, RainfallType)), Crops).

suitable_soil(Soil, SoilType) :-
    SoilType == Soil.

suitable_climate(Climate, ClimateType) :-
    ClimateType == Climate.

suitable_rainfall(Rainfall, RainfallType) :-
    RainfallType == Rainfall.

% Entry point
start:-
    write('Welcome to the Crop Suggestion System!'), nl,
    write('Please enter the soil type (e.g., loam): '),
    read(Soil),
    write('Please enter the climate type (e.g., temperate): '),
    read(Climate),
    write('Please enter the annual rainfall (e.g., moderate): '),
    read(Rainfall),
    suggest_crops(Soil, Climate, Rainfall, Crops),
    format('Suggested crops for your conditions: ~w', [Crops]).

