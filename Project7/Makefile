CC = g++
CCFLAGS = -g -w 
CCLIBS = -lncurses
TARGET = mygame
$(TARGET): main.o Item.o Gui.o Game.o Player.o Bullet.o Tank.o Bomb.o Coin.o
	$(CC) $(CCFLAGS) -o mygame main.o Item.o Gui.o Game.o Player.o Bullet.o Tank.o Bomb.o Coin.o $(CCLIBS)

Item.o: Item.h Item.C
	$(CC) $(CCFLAGS) -c -o Item.o Item.C

Gui.o: Gui.h Gui.C
	$(CC) $(CCFLAGS) -c -o Gui.o Gui.C

Game.o: Game.h Game.C
	$(CC) $(CCFLAGS) -c -o Game.o Game.C

main.o: main.C
	$(CC) $(CCFLAGS) -c -o main.o main.C

Bullet.o: Bullet.h Bullet.C
	$(CC) $(CCFLAGS) -c -o Bullet.o Bullet.C

Player.o: Player.h Player.C
	$(CC) $(CCFLAGS) -c -o Player.o Player.C

Tank.o:Tank.h Tank.C
	$(CC) $(CCFLAGS) -c -o Tank.o Tank.C

Bomb.o:Bomb.h Bomb.C
	$(CC) $(CCFLAGS) -c -o Bomb.o Bomb.C

Coin.o:Coin.h Coin.C
	$(CC) $(CCFLAGS) -c -o Coin.o Coin.C

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET) *.o

.PHONY: run clean
