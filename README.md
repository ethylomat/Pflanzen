# Pflanzen

Drawing ASCII-Trees with Ncurses


### Build
```
foo@bar$ make
g++ Bäume/main.cpp Bäume/Tree.cpp Bäume/Terminal.cpp Bäume/Game.cpp Bäume/Node.cpp Bäume/Word.cpp Bäume/Sun.cpp Bäume/helper.cpp -g -Wall -std=c++11 -lncurses -o baum
```

### Run
```
foo@bar$ ./baum
```

### Result

- Add Trees with `a`
- Clear canvas with `r`
- Quit program `q`

<img src="https://static.ethylomat.de/img/pflanzen.png"><br>