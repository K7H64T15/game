#include <iostream>
#include <globalPhaseControl.h>
#include <gtest/gtest.h>
#include <creature.h>
#include <string>
using namespace std;

TEST (phaseControl, checkFlags){
    globalPhaseControl test;
    ASSERT_EQ(test.checkFlags(),0);
}
TEST (phaseControl, checkStatus){
    globalPhaseControl test;
    player p;
    p.setHealthPointsCurrent(-1); //player is dead
    test.checkStatus(p);
    ASSERT_EQ(test.checkFlags(),1); //game over
}

TEST (creatureTest, setPoints){
    creature test;
    test.setHealthPointsCurrent(100);
    ASSERT_EQ(test.getHealthPointsCurrent(),100);
    test.setHealthPointsMax(150);
    ASSERT_EQ(test.getHealthPointsMax(),150);
    string name("name");
    test.setName(name);
    ASSERT_EQ(test.getName(),name);
}

TEST (fieldTest, setVisible){
    field test;
    test.setVisible();
    ASSERT_EQ(test.getVisible(),true);
}
TEST (fieldTest, setRoom){
    field test;
    test.setRoom();
    ASSERT_EQ(test.getEnabled(),true);
    ASSERT_EQ(test.getType(),ROOM);
}
TEST (fieldTest, setTunnel){
    field test;
    test.setTunnel(HORIZONTAL);
    ASSERT_EQ(test.getEnabled(),true);
    ASSERT_EQ(test.getType(),TUNNEL);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
