morse:
	gcc ./src/main.c ./src/input/input.c ./src/lexer/lexer.c ./src/sound/sound.c ./src/learning/learning.c -o ./bin/morse -lSDL2 -lm
