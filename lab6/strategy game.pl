% Define the knowledge base with strategy game attributes
strategy_game(hearts_of_iron, [strategy, singleplayer, pc, world_war, historical_setting]).
strategy_game(civilization, [strategy, singleplayer, pc, historical_theme, world_setting]).
strategy_game(stellaris, [strategy, multiplayer, pc, space_theme, sci-fi_setting]).
strategy_game(total_war, [strategy, multiplayer, pc, historical_theme, fantasy_setting]).
strategy_game(xcom, [strategy, singleplayer, pc, alien_theme, sci-fi_setting]).
strategy_game(crusader_kings, [strategy, singleplayer, pc, medieval_theme, historical_setting]).
strategy_game(age_of_empires, [strategy, multiplayer, pc, historical_theme, world_setting]).
strategy_game(company_of_heroes, [strategy, multiplayer, pc, world_war, historical_setting]).
strategy_game(cities_skylines, [strategy, singleplayer, pc, urban_theme, urban_setting]).
strategy_game(rise_of_nations, [strategy, multiplayer, pc, historical_theme, world_setting]).

% Check if a strategy game fits the user's preferences (backward chaining)
check_strategy_game_preferences(Game) :-
    strategy_game(Game, [Genre, SingleOrMultiplayer, Console, Theme, Setting]),
    ask_preferences('genre', Genre),
    ask_preferences('singleplayer/multiplayer', SingleOrMultiplayer),
    ask_preferences('console/pc', Console),
    ask_preferences('theme', Theme),
    ask_preferences('setting', Setting),
    format('The game ~w suits your preferences.', [Game]).

suggest_strategy_game :-
    write('What genre do you like for a strategy game? (strategy): '),
    read(Genre),
    write('Do you prefer singleplayer or multiplayer strategy games? (singleplayer/multiplayer): '),
    read(SingleOrMultiplayer),
    write('Do you prefer strategy games on console or PC? (console/pc): '),
    read(Console),
     write('Do you like strategy games with a specific theme? (historical_theme/space_theme/alien_theme/medieval_theme/world_war/urban_theme): '),
    read(Theme),
    write('Do you like strategy games set in a specific environment? (historical_setting/fantasy_setting/world_setting/sci-fi_setting ): '),
    read(Setting),
    find_matching_strategy_game(Genre, SingleOrMultiplayer, Console, Theme, Setting, Game),
    format('Recommended strategy game to play: ~w', [Game]).

find_matching_strategy_game(Genre, SingleOrMultiplayer, Console, Theme, Setting, Game) :-
    strategy_game(Game, [Genre, SingleOrMultiplayer, Console, Theme, Setting]).

