#include "Tester.hpp"

void addDelTests()
{

    std::system("./sfarchiver add arc1 ./testfiles/test1.txt");

    // test duplicate add case

    std::system("./sfarchiver add arc1 ./testfiles/test1.txt");
    std::system("./sfarchiver add arc1 ./testfiles/test1ddgd.txt");

    // delete checks

    std::system("./sfarchiver del arc1 test1.txt");
    std::system("./sfarchiver del arc1 test1.txt");
    std::system("./sfarchiver del arc1 google.png");

    //add delete add delete....

    std::system("./sfarchiver add arc1 ./testfiles/jfk.txt");
    std::system("./sfarchiver del arc1 jfk.txt");
    std::system("./sfarchiver add arc1 ./testfiles/jfk.txt");
    std::system("./sfarchiver add arc1 ./testfiles/verne.txt");
    std::system("./sfarchiver add arc1 ./testfiles/twain.txt");
    std::system("./sfarchiver add arc1 ./testfiles/test1.txt");
    std::system("./sfarchiver del arc1 twain.txt");
    std::system("./sfarchiver add arc1 ./testfiles/google.png");
    std::system("./sfarchiver del arc1 verne.txt");
    std::system("./sfarchiver del arc1 google.png");
    std::system("./sfarchiver add arc1 ./testfiles/testimg1.jpg");
    std::system("./sfarchiver del arc1 testimg1.jpg");

    //extract tests

}
void extractTests()
{
    std::system("./sfarchiver add arc2 ./testfiles/test1.txt");
    std::system("./sfarchiver add arc2 ./testfiles/test2.txt");
    std::system("./sfarchiver del arc2 test1.txt");
    std::system("./sfarchiver extract arc2 test2.txt");
    std::system("./sfarchiver del arc2 test2.txt");

}

void mulAddDel()
{
  std::system("./sfarchiver add arc1 ./testfiles/test1.txt");
  std::system("./sfarchiver add arc1 ./testfiles/test2.txt");
  std::system("./sfarchiver add arc1 ./testfiles/test3.txt");
  std::system("./sfarchiver add arc1 ./testfiles/jfk.txt");
  std::system("./sfarchiver add arc1 ./testfiles/google.png");
  std::system("./sfarchiver add arc1 ./testfiles/UCSD.png");
  std::system("./sfarchiver del arc1 jfk.txt");
  std::system("./sfarchiver del arc1 google.png");
  std::system("./sfarchiver del arc1 UCSD.png");
  std::system("./sfarchiver del arc1 test1.txt");
  std::system("./sfarchiver del arc1 test2.txt");
  std::system("./sfarchiver del arc1 test3.txt");

}


void performanceTests()
{
    std::cout<<"Performance Test 1. Deleting a small file stored after two large files"<<std::endl;
    std::system("./sfarchiver add arc1 ./testfiles/alice.txt");
    std::system("./sfarchiver add arc1 ./testfiles/test1.txt");
    std::system("./sfarchiver add arc1 ./testfiles/test2.txt");
    std::system("./sfarchiver add arc1 ./testfiles/test3.txt");
    std::system("./sfarchiver add arc1 ./testfiles/google.png");
    std::system("./sfarchiver add arc1 ./testfiles/verne.txt");
    std::system("./sfarchiver add arc1 ./testfiles/twain.txt");
    std::system("./sfarchiver add arc1 ./testfiles/jfk.txt");
    auto start = std::chrono::system_clock::now(); // start timer
    std::system("./sfarchiver del arc1 jfk.txt");
    std::system("./sfarchiver del arc1 twain.txt");
    std::system("./sfarchiver del arc1 verne.txt");
    auto end = std::chrono::system_clock::now();

    std::cout<<"Performance Test 2. Deleting a small file stored first"<<std::endl;
    std::system("./sfarchiver add arc2 ./testfiles/jfk.txt");
    std::system("./sfarchiver add arc2 ./testfiles/verne.txt");
    std::system("./sfarchiver add arc2 ./testfiles/twain.txt");
    auto start1 = std::chrono::system_clock::now();
    std::system("./sfarchiver del arc2 jfk.txt");
    std::system("./sfarchiver del arc2 twain.txt");
    std::system("./sfarchiver del arc2 verne.txt");
    auto end1 = std::chrono::system_clock::now();
    std::cout<<"Comparing execution times"<<std::endl;
    std::cout<< "Performance Test1 has taken "<<std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << " microseconds to run."<<std::endl;
    std::cout<< "Performance Test2 has taken "<<std::chrono::duration_cast<std::chrono::microseconds>(end1-start1).count() << " microseconds to run."<<std::endl;
}

void listTests()
{
    std::cout<<"List Tests"<<std::endl;
    std::system("./sfarchiver -l arc3");
    std::system("./sfarchiver add arc3 ./testfiles/alice.txt");
    std::system("./sfarchiver -l arc3");
    std::system("./sfarchiver -l arc3 alice.txt");

}



void findTests()
{
    std::cout<<"Find Tests"<<std::endl;
    std::system("./sfarchiver add arc5 ./testfiles/twain.txt");
    std::system("./sfarchiver add arc5 ./testfiles/alice.txt");
    std::system("./sfarchiver find arc5 is");
}

void versionTest()
{
  std::system("./sfarchiver -v");
}


void Tester:: runTests()
{
    addDelTests();
    extractTests();
    mulAddDel();
    addDelTests();
    extractTests();
    performanceTests();
    listTests();
    findTests();
    versionTest();

}
