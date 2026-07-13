CC = g++
CCFLAGS = -g 
CCLIBS = -lncurses
TARGET = mygame
$(TARGET): main.o Gui.o Game.o Item.o Player.o Bullet.o Tank.o RemovableItem.o EnemyTank.o NormalTank.o SuperTank.o Mine.o MedicalPack.o LaserTank.o Obstacle.o
	$(CC) $(CCFLAGS) -o mygame main.o Gui.o Game.o Item.o Player.o Bullet.o Tank.o RemovableItem.o EnemyTank.o NormalTank.o SuperTank.o Mine.o MedicalPack.o LaserTank.o Obstacle.o $(CCLIBS)

Gui.o: Gui.h Gui.C
	$(CC) $(CCFLAGS) -c -o Gui.o Gui.C

Game.o: Game.h Game.C
	$(CC) $(CCFLAGS) -c -o Game.o Game.C

main.o: main.C
	$(CC) $(CCFLAGS) -c -o main.o main.C

Item.o: Item.C Item.h
	$(CC) $(CCFLAGS) -c -o Item.o Item.C

Bullet.o: Bullet.h Bullet.C
	$(CC) $(CCFLAGS) -c -o Bullet.o Bullet.C

Player.o: Player.h Player.C
	$(CC) $(CCFLAGS) -c -o Player.o Player.C

Tank.o: Tank.h Tank.C
	$(CC) $(CCFLAGS) -c -o Tank.o Tank.C

RemovableItem.o: RemovableItem.h RemovableItem.C
	$(CC) $(CCFLAGS) -c -o RemovableItem.o RemovableItem.C

EnemyTank.o: EnemyTank.h EnemyTank.C
	$(CC) $(CCFLAGS) -c -o EnemyTank.o EnemyTank.C

NormalTank.o: NormalTank.h NormalTank.C
	$(CC) $(CCFLAGS) -c -o NormalTank.o NormalTank.C

SuperTank.o: SuperTank.h SuperTank.C
	$(CC) $(CCFLAGS) -c -o SuperTank.o SuperTank.C

Mine.o: Mine.h Mine.C
	$(CC) $(CCFLAGS) -c -o Mine.o Mine.C

MedicalPack.o: MedicalPack.h MedicalPack.C
	$(CC) $(CCFLAGS) -c -o MedicalPack.o MedicalPack.C

LaserTank.o: LaserTank.h LaserTank.C
	$(CC) $(CCFLAGS) -c -o LaserTank.o LaserTank.C

Obstacle.o: Obstacle.h Obstacle.C
	$(CC) $(CCFLAGS) -c -o Obstacle.o Obstacle.C

.PHONY: run clean

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(TARGET) *.o
