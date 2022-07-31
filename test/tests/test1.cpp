#include <gtest/gtest.h>
#include <QDebug>
#include "../../inc/database.h"


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

//TEST(DataBase_test, first_test) {
//	DataBase db("database_example.db");
//   if (db.isOpen())
//   {
//       db.createTable();
//       db.addElement("Monday", 10.5, 1000);
//       db.addElement("Tuesday", 20.5, 1500);
//       db.addElement("Wednesday", 30.5, 2000);

//       db.printAll();
//       db.removeElement("Monday");
//       db.printAll();
//       db.clearDataBase();
//       qDebug() << "End";
//   }
//   else
//       qDebug() << "Database is not open!";
//}
