//
// Created by akhtyamovpavel on 5/1/20.
//
#include <fstream>
#include "TreeTestCase.h"
#include "Tree.h"


TEST(gettree, tree) {
    try {
        GetTree("nonexistent_path", 0);
    } catch (...) {}
    try {
        GetTree("Makefile", 0);
    } catch (...) {}
    GetTree(".", 0);
    GetTree(".", 1);
}

TEST(filteremptynodes, tree) {
    std::filesystem::create_directories(".\\tmp");
    std::ofstream f1(".\\tmp\\f1.txt");
    f1.close();
    std::filesystem::create_directories(".\\tmp\\tmp1");
    std::ofstream f2(".\\tmp\\tmp1\\f2.txt");
    f2.close();
    std::ofstream f3(".\\tmp\\tmp1\\f3.txt");
    f3.close();
    std::filesystem::create_directories(".\\tmp\\tmp2");
    FileNode tmp2 = GetTree(".\\tmp\\tmp2", 0);
    try {
        FilterEmptyNodes(tmp2, ".");
    } catch (...) {}
    FilterEmptyNodes(tmp2, ".\\tmp\\tmp2");
    FileNode tmp1 = GetTree(".\\tmp\\tmp1", 0);
    FilterEmptyNodes(tmp1, ".\\tmp\\tmp1");
    FilterEmptyNodes({"1", 0, {}}, ".");
    FilterEmptyNodes({"1", 1, {{"1", 0, {}}, {"1", 0, {}}}}, ".");
    ASSERT_TRUE(tmp1 == tmp1);
    std::filesystem::remove_all(".\\tmp");
}