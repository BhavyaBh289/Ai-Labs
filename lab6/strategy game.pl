% Define the knowledge base with strategy game attributes
strategy_game(hearts_of_iron, [singleplayer, pc, world_war, historical_setting]).
strategy_game(civilization, [singleplayer, pc, historical_theme, world_setting]).
strategy_game(stellaris, [multiplayer, pc, space_theme, sci-fi_setting]).
strategy_game(total_war, [multiplayer, pc, historical_theme, fantasy_setting]).
strategy_game(xcom, [singleplayer, pc, alien_theme, sci-fi_setting]).
strategy_game(crusader_kings, [singleplayer, pc, medieval_theme, historical_setting]).
strategy_game(age_of_empires, [multiplayer, pc, historical_theme, world_setting]).
strategy_game(company_of_heroes, [multiplayer, pc, world_war, historical_setting]).
strategy_game(cities_skylines, [singleplayer, pc, urban_theme, urban_setting]).
strategy_game(rise_of_nations, [multiplayer, pc, historical_theme, world_setting]).

% Check if a strategy game fits the user's preferences (backward chaining)
check_strategy_game_preferences(Game) :-
    strategy_game(Game, [SingleOrMultiplayer, Console, Theme, Setting]),
    ask_preferences('singleplayer/multiplayer', SingleOrMultiplayer),
    ask_preferences('console/pc', Console),
    ask_preferences('theme', Theme),
    ask_preferences('setting', Setting),
    format('The game ~w suits your preferences.', [Game]).

suggest_strategy_game :-
    write('Do you prefer singleplayer or multiplayer strategy games? (singleplayer/multiplayer): '),
    read(SingleOrMultiplayer),
    write('Do you prefer strategy games on console or PC? (console/pc): '),
    read(Console),
    write('Do you like strategy games with a specific theme? (historical_theme/space_theme/alien_theme/medieval_theme/world_war/urban_theme): '),
    read(Theme),
    write('Do you like strategy games set in a specific environment? (historical_setting/fantasy_setting/world_setting/sci-fi_setting ): '),
    read(Setting),
    find_matching_strategy_game(SingleOrMultiplayer, Console, Theme, Setting, Game),
    format('Recommended strategy game to play: ~w', [Game]).

find_matching_strategy_game(SingleOrMultiplayer, Console, Theme, Setting, Game) :-
    strategy_game(Game, [SingleOrMultiplayer, Console, Theme, Setting]).
