#include "singleton.hpp"
#include <gtest/gtest.h>

//TEST(DatabaseTests, IsSingletonTest)
//{
//  auto& db = SingletonDatabase::get();
//  auto& db2 = SingletonDatabase::get();
//  ASSERT_EQ(1, db.instance_count);
//  ASSERT_EQ(1, db2.instance_count);
//}


// Problem with Singleton:
// This is not a unit test, as SingletonRecordFinder and
// SingletonDatabase are strongly coupled
TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
  SingletonRecordFinder rf;
  std::vector<std::string> names{ "Great White", "Packard" };
  int ts = rf.total_stock(names);
  EXPECT_EQ(2 + 3, ts);
}

// TEST(RecordFinderTests, DependantTotalPopulationTest)
// {
//   DummyDatabase db{};
//   ConfigurableRecordFinder rf{ db };
//   EXPECT_EQ(4, rf.total_population(
//     std::vector<std::string>{"alpha", "gamma"}));
// }

int dsfmain(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av); 
  return RUN_ALL_TESTS();
}
