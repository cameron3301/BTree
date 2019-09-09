/* 
 *  main function
 */

#include "BTree.h"
#include <iostream>
#include <fstream>
#include <string>

BTree read_file(string file_name)
{
    BTree tree;
    /*
        open the file and use the input operator (operator>>)
        to construct a new tree
    */

    ifstream in(file_name);
    in >> tree;

    return tree;
}


int main()
{
    // testing the ability to read data from text files into BTree's
    BTree t1 = read_file("data-files/4r");
    BTree t2 = read_file("data-files/3p");
    BTree t3 = read_file("data-files/2l");

    // test: print_level_byz-level function
    cout << "Print trees t1, t2, and t3." << endl;
    cout << "t1: \n" << t1 << endl << endl;
    cout << "t2: \n" << t2 << endl << endl;
    cout << "t3: \n" << t3 << endl << endl;

    // test: inorder function
    cout << "Print t1 using the inorder function to output file 'inorder-test'." << endl;
    string out_inorder_filename = "output-data-files/inorder-test";
    ofstream out_inorder_test(out_inorder_filename);
    
    

    // test: copy constructor
    cout << "Create a copy of the t1 tree called copy_t1 using the copy constructor." << endl;
    BTree copy_t1(t1);
    cout << "copy_t1: \n" << copy_t1 << endl << endl;

    // test: copy assignment operator
    cout << "Create a copy of the t2 tree called copy_t2 using the copy assignment operator." << endl;
    BTree copy_t2 = t2;
    cout << "copy_t2: \n" << copy_t2 << endl << endl;

    // test: move constructor
    cout << "Move the copy_t1 tree to a tree called move_t1 using the move constructor." << endl;
    BTree move_t1(move(copy_t1));
    cout << "move_t1: \n" << move_t1 << endl << endl;

    // test: move assignment operator
    cout << "Move the copy_t2 tree to a tree called move_t2 using the move assignment operator." << endl;
    BTree move_t2 = move(copy_t2);
    cout << "move_t2: \n" << move_t2 << endl << endl;

    // test: search function
    cout << "Search for the node with value 9 in tree t1." << endl;
    cout << "Node: " << t1.search(9) << endl << endl;

    // test: insert function
    cout << "Insert the numbers 16 and 17 into tree t1." << endl;
    t1.insert(16);
    t1.insert(17);
    cout << "t1: \n" << t1 << endl << endl;

    // test: update_search_cost function
    cout << "Execute the update_search_cost function." << endl;
    t1.update_search_cost();
    cout << "t1: \n" << t1 << endl << endl;


    cout << "(size, average_search_cost)" << endl;

    // create variables for the input filenames 1-12l, 1-12p, and 1-12r
    string l1_filename = "data-files/1l";
    string l2_filename = "data-files/2l";
    string l3_filename = "data-files/3l";
    string l4_filename = "data-files/4l";
    string l5_filename = "data-files/5l";
    string l6_filename = "data-files/6l";
    string l7_filename = "data-files/7l";
    string l8_filename = "data-files/8l";
    string l9_filename = "data-files/9l";
    string l10_filename = "data-files/10l";
    string l11_filename = "data-files/11l";
    string l12_filename = "data-files/12l";
    string p1_filename = "data-files/1p";
    string p2_filename = "data-files/2p";
    string p3_filename = "data-files/3p";
    string p4_filename = "data-files/4p";
    string p5_filename = "data-files/5p";
    string p6_filename = "data-files/6p";
    string p7_filename = "data-files/7p";
    string p8_filename = "data-files/8p";
    string p9_filename = "data-files/9p";
    string p10_filename = "data-files/10p";
    string p11_filename = "data-files/11p";
    string p12_filename = "data-files/12p";
    string r1_filename = "data-files/1r";
    string r2_filename = "data-files/2r";
    string r3_filename = "data-files/3r";
    string r4_filename = "data-files/4r";
    string r5_filename = "data-files/5r";
    string r6_filename = "data-files/6r";
    string r7_filename = "data-files/7r";
    string r8_filename = "data-files/8r";
    string r9_filename = "data-files/9r";
    string r10_filename = "data-files/10r";
    string r11_filename = "data-files/11r";
    string r12_filename = "data-files/12r";

    // read the data for input files 1-12l, 1-12p, and 1-12r into BTree objects
    BTree l1 = read_file(l1_filename);
    BTree l2 = read_file(l2_filename);
    BTree l3 = read_file(l3_filename);
    BTree l4 = read_file(l4_filename);
    BTree l5 = read_file(l5_filename);
    BTree l6 = read_file(l6_filename);
    BTree l7 = read_file(l7_filename);
    BTree l8 = read_file(l8_filename);
    BTree l9 = read_file(l9_filename);
    BTree l10 = read_file(l10_filename);
    BTree l11 = read_file(l11_filename);
    BTree l12 = read_file(l12_filename);
    BTree p1 = read_file(p1_filename);
    BTree p2 = read_file(p2_filename);
    BTree p3 = read_file(p3_filename);
    BTree p4 = read_file(p4_filename);
    BTree p5 = read_file(p5_filename);
    BTree p6 = read_file(p6_filename);
    BTree p7 = read_file(p7_filename);
    BTree p8 = read_file(p8_filename);
    BTree p9 = read_file(p9_filename);
    BTree p10 = read_file(p10_filename);
    BTree p11 = read_file(p11_filename);
    BTree p12 = read_file(p12_filename);
    BTree r1 = read_file(r1_filename);
    BTree r2 = read_file(r2_filename);
    BTree r3 = read_file(r3_filename);
    BTree r4 = read_file(r4_filename);
    BTree r5 = read_file(r5_filename);
    BTree r6 = read_file(r6_filename);
    BTree r7 = read_file(r7_filename);
    BTree r8 = read_file(r8_filename);
    BTree r9 = read_file(r9_filename);
    BTree r10 = read_file(r10_filename);
    BTree r11 = read_file(r11_filename);
    BTree r12 = read_file(r12_filename);

    // print the size and the average search costs for the linear binary search trees below
    cout << "1l:  (" << l1.get_size() << ", " << l1.avg_search_cost() << ")" << endl;
    cout << "2l:  (" << l2.get_size() << ", " << l2.avg_search_cost() << ")" << endl;
    cout << "3l:  (" << l3.get_size() << ", " << l3.avg_search_cost() << ")" << endl;
    cout << "4l:  (" << l4.get_size() << ", " << l4.avg_search_cost() << ")" << endl;
    cout << "5l:  (" << l5.get_size() << ", " << l5.avg_search_cost() << ")" << endl;
    cout << "6l:  (" << l6.get_size() << ", " << l6.avg_search_cost() << ")" << endl;
    cout << "7l:  (" << l7.get_size() << ", " << l7.avg_search_cost() << ")" << endl;
    cout << "8l:  (" << l8.get_size() << ", " << l8.avg_search_cost() << ")" << endl;
    cout << "9l:  (" << l9.get_size() << ", " << l9.avg_search_cost() << ")" << endl;
    cout << "10l: (" << l10.get_size() << ", " << l10.avg_search_cost() << ")" << endl;
    cout << "11l: (" << l11.get_size() << ", " << l11.avg_search_cost() << ")" << endl;
    cout << "12l: (" << l12.get_size() << ", " << l12.avg_search_cost() << ")" << endl;

    cout << endl;

    // print the size and the average search costs for the perfect binary search trees below
    cout << "1p:  (" << p1.get_size() << ", " << p1.avg_search_cost() << ")" << endl;
    cout << "2p:  (" << p2.get_size() << ", " << p2.avg_search_cost() << ")" << endl;
    cout << "3p:  (" << p3.get_size() << ", " << p3.avg_search_cost() << ")" << endl;
    cout << "4p:  (" << p4.get_size() << ", " << p4.avg_search_cost() << ")" << endl;
    cout << "5p:  (" << p5.get_size() << ", " << p5.avg_search_cost() << ")" << endl;
    cout << "6p:  (" << p6.get_size() << ", " << p6.avg_search_cost() << ")" << endl;
    cout << "7p:  (" << p7.get_size() << ", " << p7.avg_search_cost() << ")" << endl;
    cout << "8p:  (" << p8.get_size() << ", " << p8.avg_search_cost() << ")" << endl;
    cout << "9p:  (" << p9.get_size() << ", " << p9.avg_search_cost() << ")" << endl;
    cout << "10p: (" << p10.get_size() << ", " << p10.avg_search_cost() << ")" << endl;
    cout << "11p: (" << p11.get_size() << ", " << p11.avg_search_cost() << ")" << endl;
    cout << "12p: (" << p12.get_size() << ", " << p12.avg_search_cost() << ")" << endl;

    cout << endl;

    // print the size and the average search costs for the random binary search trees below
    cout << "1r:  (" << r1.get_size() << ", " << r1.avg_search_cost() << ")" << endl;
    cout << "2r:  (" << r2.get_size() << ", " << r2.avg_search_cost() << ")" << endl;
    cout << "3r:  (" << r3.get_size() << ", " << r3.avg_search_cost() << ")" << endl;
    cout << "4r:  (" << r4.get_size() << ", " << r4.avg_search_cost() << ")" << endl;
    cout << "5r:  (" << r5.get_size() << ", " << r5.avg_search_cost() << ")" << endl;
    cout << "6r:  (" << r6.get_size() << ", " << r6.avg_search_cost() << ")" << endl;
    cout << "7r:  (" << r7.get_size() << ", " << r7.avg_search_cost() << ")" << endl;
    cout << "8r:  (" << r8.get_size() << ", " << r8.avg_search_cost() << ")" << endl;
    cout << "9r:  (" << r9.get_size() << ", " << r9.avg_search_cost() << ")" << endl;
    cout << "10r: (" << r10.get_size() << ", " << r10.avg_search_cost() << ")" << endl;
    cout << "11r: (" << r11.get_size() << ", " << r11.avg_search_cost() << ")" << endl;
    cout << "12r: (" << r12.get_size() << ", " << r12.avg_search_cost() << ")" << endl;

    // create variables for the output filenames 1-4l, 1-4p, and 1-4r
    string l1_out_filename = "output-data-files/1l";
    string l2_out_filename = "output-data-files/2l";
    string l3_out_filename = "output-data-files/3l";
    string l4_out_filename = "output-data-files/4l";
    string p1_out_filename = "output-data-files/1p";
    string p2_out_filename = "output-data-files/2p";
    string p3_out_filename = "output-data-files/3p";
    string p4_out_filename = "output-data-files/4p";
    string r1_out_filename = "output-data-files/1r";
    string r2_out_filename = "output-data-files/2r";
    string r3_out_filename = "output-data-files/3r";
    string r4_out_filename = "output-data-files/4r";

    // create ofstream's for the BST's associated with input files 1-4l, 1-4p, and 1-4r
    ofstream out_1l(l1_out_filename);
    ofstream out_2l(l2_out_filename);
    ofstream out_3l(l3_out_filename);
    ofstream out_4l(l4_out_filename);
    ofstream out_1p(p1_out_filename);
    ofstream out_2p(p2_out_filename);
    ofstream out_3p(p3_out_filename);
    ofstream out_4p(p4_out_filename);
    ofstream out_1r(r1_out_filename);
    ofstream out_2r(r2_out_filename);
    ofstream out_3r(r3_out_filename);
    ofstream out_4r(r4_out_filename);

    // print the BST's associated with input files 1-4l, 1-4p, and 1-4r to their corresponding output file
    out_1l << l1;
    out_2l << l2;
    out_3l << l3;
    out_4l << l4;
    out_1p << p1;
    out_2p << p2;
    out_3p << p3;
    out_4p << p4;
    out_1r << r1;
    out_2r << r2;
    out_3r << r3;
    out_4r << r4;


}


