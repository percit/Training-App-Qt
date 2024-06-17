#include <gtest/gtest.h>
#include "DataBaseModel.h"

TEST(MyTestSuite, TestBasicSetters)
{
  DataBaseModel *database = new DataBaseModel();
  database->setDatabaseName("test_database.db");
  database->initializeDataBase();
  database->setweeklyMetersRun(100);
  database->setLongestDistance(200);
  database->setLongestDuration(300);
  database->setBestPace(400);
  database->setAverageDuration(500);
  database->setAllDuration(600);
  database->setWeeklyGoal(700);
  database->setDailyGoal(800);
  database->setMail("test@gmail.com");

  EXPECT_EQ(100, database->weeklyMetersRun());
  EXPECT_EQ(200, database->longestDistance());  
  EXPECT_EQ(300, database->longestDuration());
  EXPECT_EQ(400, database->bestPace());
  EXPECT_EQ(500, database->averageDuration());
  EXPECT_EQ(600, database->allDuration());
  EXPECT_EQ(700, database->weeklyGoal());
  EXPECT_EQ(800, database->dailyGoal());
  // EXPECT_EQ("test@gmail.com", database->mail()); TODO THIS WON'T WORK
}

TEST(MyTestSuite, TestUpdateAllMaxes)
{
  DataBaseModel *database = new DataBaseModel();
  database->setDatabaseName("test_database.db");
  database->setWeek("Monday", 1000, 300);
  database->setWeek("Tuesday", 2000,  2*300);
  database->setWeek("Wednesday", 3000, 3*300);
  database->setWeek("Thursday", 4000, 4*300);
  database->setWeek("Friday", 5000, 5*300);
  database->setWeek("Saturday", 6000, 6*300);
  database->setWeek("Sunday", 7000, 7*300);

  database->updateAllMaxes();

  EXPECT_EQ(28000, database->weeklyMetersRun());
  EXPECT_EQ(7000, database->longestDistance());  
  EXPECT_EQ(2100, database->longestDuration());
  EXPECT_EQ(3, database->bestPace());
  EXPECT_EQ(1200, database->averageDuration());
  EXPECT_EQ(8400, database->allDuration());
}

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}