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
// This cannot be considered a unit test, as SingletonRecordFinder and
// SingletonDatabase are strongly coupled
// This is an integration test, as it tests the RecordFinders integration with the Database.
TEST(RecordFinderTests, SingletonTotalPopulationTest)
{
  SingletonRecordFinder rf;
  std::vector<std::string> names{ "Great White", "Packard" };
  int ts = rf.total_stock(names);
  EXPECT_EQ(2 + 3, ts);
}

// This is a proper unit test as we don't need to go into the actual
// Database to test Record Finder
// but through a DummyDatabase where we have full control on the data
TEST(RecordFinderTests, DependantTotalPopulationTest)
{
  DummyDatabase db{};
  ConfigurableRecordFinder rf{ db };
  EXPECT_EQ(4, rf.total_stock(
    std::vector<std::string>{"astro", "coin"}));
}

int dsfmain(int ac, char* av[])
{
  testing::InitGoogleTest(&ac, av); 
  return RUN_ALL_TESTS();
}
