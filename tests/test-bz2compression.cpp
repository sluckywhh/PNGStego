//
// Copyright (C) 2015 Zireael (zireael dot nk at gmail dot com)
//  Distributed under the Boost Software License, Version 1.0.
//       (See accompanying file LICENSE.md or copy at
//           http://www.boost.org/LICENSE_1_0.txt)
//

#include <iostream>
#include <vector>
#include <random>
#include "bz2compression.h"

const std::vector<uint8_t> originalData =  { 66, 111, 111, 115, 116, 32, 83, 111, 102, 116, 119, 97, 114, 101, 32, 76, 105, 99, 101, 110, 115, 101, 32, 45, 32,
                                             86, 101, 114, 115, 105, 111, 110, 32, 49, 46, 48, 32, 45, 32, 65, 117, 103, 117, 115, 116, 32, 49, 55, 116, 104,
                                             44, 32, 50, 48, 48, 51, 10, 10, 80, 101, 114, 109, 105, 115, 115, 105, 111, 110, 32, 105, 115, 32, 104, 101, 114,
                                             101, 98, 121, 32, 103, 114, 97, 110, 116, 101, 100, 44, 32, 102, 114, 101, 101, 32, 111, 102, 32, 99, 104, 97, 114,
                                             103, 101, 44, 32, 116, 111, 32, 97, 110, 121, 32, 112, 101, 114, 115, 111, 110, 32, 111, 114, 32, 111, 114, 103, 97,
                                             110, 105, 122, 97, 116, 105, 111, 110, 10, 111, 98, 116, 97, 105, 110, 105, 110, 103, 32, 97, 32, 99, 111, 112, 121,
                                             32, 111, 102, 32, 116, 104, 101, 32, 115, 111, 102, 116, 119, 97, 114, 101, 32, 97, 110, 100, 32, 97, 99, 99, 111,
                                             109, 112, 97, 110, 121, 105, 110, 103, 32, 100, 111, 99, 117, 109, 101, 110, 116, 97, 116, 105, 111, 110, 32, 99, 111,
                                             118, 101, 114, 101, 100, 32, 98, 121, 10, 116, 104, 105, 115, 32, 108, 105, 99, 101, 110, 115, 101, 32, 40, 116, 104,
                                             101, 32, 34, 83, 111, 102, 116, 119, 97, 114, 101, 34, 41, 32, 116, 111, 32, 117, 115, 101, 44, 32, 114, 101, 112,
                                             114, 111, 100, 117, 99, 101, 44, 32, 100, 105, 115, 112, 108, 97, 121, 44, 32, 100, 105, 115, 116, 114, 105, 98, 117,
                                             116, 101, 44, 10, 101, 120, 101, 99, 117, 116, 101, 44, 32, 97, 110, 100, 32, 116, 114, 97, 110, 115, 109, 105, 116,
                                             32, 116, 104, 101, 32, 83, 111, 102, 116, 119, 97, 114, 101, 44, 32, 97, 110, 100, 32, 116, 111, 32, 112, 114, 101,
                                             112, 97, 114, 101, 32, 100, 101, 114, 105, 118, 97, 116, 105, 118, 101, 32, 119, 111, 114, 107, 115, 32, 111, 102, 32,
                                             116, 104, 101, 10, 83, 111, 102, 116, 119, 97, 114, 101, 44, 32, 97, 110, 100, 32, 116, 111, 32, 112, 101, 114, 109,
                                             105, 116, 32, 116, 104, 105, 114, 100, 45, 112, 97, 114, 116, 105, 101, 115, 32, 116, 111, 32, 119, 104, 111, 109, 32,
                                             116, 104, 101, 32, 83, 111, 102, 116, 119, 97, 114, 101, 32, 105, 115, 32, 102, 117, 114, 110, 105, 115, 104, 101, 100,
                                             32, 116, 111, 10, 100, 111, 32, 115, 111, 44, 32, 97, 108, 108, 32, 115, 117, 98, 106, 101, 99, 116, 32, 116, 111,
                                             32, 116, 104, 101, 32, 102, 111, 108, 108, 111, 119, 105, 110, 103, 58, 10, 10, 84, 104, 101, 32, 99, 111, 112, 121,
                                             114, 105, 103, 104, 116, 32, 110, 111, 116, 105, 99, 101, 115, 32, 105, 110, 32, 116, 104, 101, 32, 83, 111, 102, 116,
                                             119, 97, 114, 101, 32, 97, 110, 100, 32, 116, 104, 105, 115, 32, 101, 110, 116, 105, 114, 101, 32, 115, 116, 97, 116,
                                             101, 109, 101, 110, 116, 44, 32, 105, 110, 99, 108, 117, 100, 105, 110, 103, 10, 116, 104, 101, 32, 97, 98, 111, 118,
                                             101, 32, 108, 105, 99, 101, 110, 115, 101, 32, 103, 114, 97, 110, 116, 44, 32, 116, 104, 105, 115, 32, 114, 101, 115,
                                             116, 114, 105, 99, 116, 105, 111, 110, 32, 97, 110, 100, 32, 116, 104, 101, 32, 102, 111, 108, 108, 111, 119, 105, 110,
                                             103, 32, 100, 105, 115, 99, 108, 97, 105, 109, 101, 114, 44, 10, 109, 117, 115, 116, 32, 98, 101, 32, 105, 110, 99,
                                             108, 117, 100, 101, 100, 32, 105, 110, 32, 97, 108, 108, 32, 99, 111, 112, 105, 101, 115, 32, 111, 102, 32, 116, 104,
                                             101, 32, 83, 111, 102, 116, 119, 97, 114, 101, 44, 32, 105, 110, 32, 119, 104, 111, 108, 101, 32, 111, 114, 32, 105,
                                             110, 32, 112, 97, 114, 116, 44, 32, 97, 110, 100, 10, 97, 108, 108, 32, 100, 101, 114, 105, 118, 97, 116, 105, 118,
                                             101, 32, 119, 111, 114, 107, 115, 32, 111, 102, 32, 116, 104, 101, 32, 83, 111, 102, 116, 119, 97, 114, 101, 44, 32,
                                             117, 110, 108, 101, 115, 115, 32, 115, 117, 99, 104, 32, 99, 111, 112, 105, 101, 115, 32, 111, 114, 32, 100, 101, 114,
                                             105, 118, 97, 116, 105, 118, 101, 10, 119, 111, 114, 107, 115, 32, 97, 114, 101, 32, 115, 111, 108, 101, 108, 121, 32,
                                             105, 110, 32, 116, 104, 101, 32, 102, 111, 114, 109, 32, 111, 102, 32, 109, 97, 99, 104, 105, 110, 101, 45, 101, 120,
                                             101, 99, 117, 116, 97, 98, 108, 101, 32, 111, 98, 106, 101, 99, 116, 32, 99, 111, 100, 101, 32, 103, 101, 110, 101,
                                             114, 97, 116, 101, 100, 32, 98, 121, 10, 97, 32, 115, 111, 117, 114, 99, 101, 32, 108, 97, 110, 103, 117, 97, 103,
                                             101, 32, 112, 114, 111, 99, 101, 115, 115, 111, 114, 46, 10, 10, 84, 72, 69, 32, 83, 79, 70, 84, 87, 65, 82,
                                             69, 32, 73, 83, 32, 80, 82, 79, 86, 73, 68, 69, 68, 32, 34, 65, 83, 32, 73, 83, 34, 44, 32, 87, 73,
                                             84, 72, 79, 85, 84, 32, 87, 65, 82, 82, 65, 78, 84, 89, 32, 79, 70, 32, 65, 78, 89, 32, 75, 73, 78,
                                             68, 44, 32, 69, 88, 80, 82, 69, 83, 83, 32, 79, 82, 10, 73, 77, 80, 76, 73, 69, 68, 44, 32, 73, 78,
                                             67, 76, 85, 68, 73, 78, 71, 32, 66, 85, 84, 32, 78, 79, 84, 32, 76, 73, 77, 73, 84, 69, 68, 32, 84,
                                             79, 32, 84, 72, 69, 32, 87, 65, 82, 82, 65, 78, 84, 73, 69, 83, 32, 79, 70, 32, 77, 69, 82, 67, 72,
                                             65, 78, 84, 65, 66, 73, 76, 73, 84, 89, 44, 10, 70, 73, 84, 78, 69, 83, 83, 32, 70, 79, 82, 32, 65,
                                             32, 80, 65, 82, 84, 73, 67, 85, 76, 65, 82, 32, 80, 85, 82, 80, 79, 83, 69, 44, 32, 84, 73, 84, 76,
                                             69, 32, 65, 78, 68, 32, 78, 79, 78, 45, 73, 78, 70, 82, 73, 78, 71, 69, 77, 69, 78, 84, 46, 32, 73,
                                             78, 32, 78, 79, 32, 69, 86, 69, 78, 84, 10, 83, 72, 65, 76, 76, 32, 84, 72, 69, 32, 67, 79, 80, 89,
                                             82, 73, 71, 72, 84, 32, 72, 79, 76, 68, 69, 82, 83, 32, 79, 82, 32, 65, 78, 89, 79, 78, 69, 32, 68,
                                             73, 83, 84, 82, 73, 66, 85, 84, 73, 78, 71, 32, 84, 72, 69, 32, 83, 79, 70, 84, 87, 65, 82, 69, 32,
                                             66, 69, 32, 76, 73, 65, 66, 76, 69, 10, 70, 79, 82, 32, 65, 78, 89, 32, 68, 65, 77, 65, 71, 69, 83,
                                             32, 79, 82, 32, 79, 84, 72, 69, 82, 32, 76, 73, 65, 66, 73, 76, 73, 84, 89, 44, 32, 87, 72, 69, 84,
                                             72, 69, 82, 32, 73, 78, 32, 67, 79, 78, 84, 82, 65, 67, 84, 44, 32, 84, 79, 82, 84, 32, 79, 82, 32,
                                             79, 84, 72, 69, 82, 87, 73, 83, 69, 44, 10, 65, 82, 73, 83, 73, 78, 71, 32, 70, 82, 79, 77, 44, 32,
                                             79, 85, 84, 32, 79, 70, 32, 79, 82, 32, 73, 78, 32, 67, 79, 78, 78, 69, 67, 84, 73, 79, 78, 32, 87,
                                             73, 84, 72, 32, 84, 72, 69, 32, 83, 79, 70, 84, 87, 65, 82, 69, 32, 79, 82, 32, 84, 72, 69, 32, 85,
                                             83, 69, 32, 79, 82, 32, 79, 84, 72, 69, 82, 10, 68, 69, 65, 76, 73, 78, 71, 83, 32, 73, 78, 32, 84,
                                             72, 69, 32, 83, 79, 70, 84, 87, 65, 82, 69, 46 };

const std::vector<uint8_t> bz2Data =  { 66, 90, 104, 57, 49, 65, 89, 38, 83, 89, 97, 65, 198, 120, 0, 0, 148, 223, 128, 0, 16, 80, 103, 120, 144,
                                        63, 239, 223, 224, 63, 255, 223, 240, 64, 3, 11, 91, 187, 179, 84, 2, 132, 77, 19, 26, 167, 163, 80, 30, 166,
                                        158, 166, 141, 52, 50, 52, 0, 26, 100, 0, 137, 132, 158, 73, 132, 34, 109, 67, 2, 12, 153, 50, 0, 100, 196,
                                        3, 70, 133, 50, 41, 250, 80, 222, 169, 234, 61, 64, 208, 0, 6, 158, 160, 25, 13, 4, 166, 144, 4, 153, 52,
                                        25, 18, 100, 3, 70, 128, 201, 144, 13, 4, 36, 210, 148, 112, 29, 83, 109, 56, 125, 221, 81, 5, 92, 146, 185,
                                        4, 28, 41, 242, 184, 154, 57, 70, 52, 75, 56, 31, 120, 234, 42, 84, 235, 65, 122, 61, 73, 158, 117, 82, 81,
                                        181, 21, 136, 65, 234, 70, 76, 232, 104, 121, 160, 5, 145, 112, 106, 167, 125, 22, 216, 216, 53, 220, 52, 105, 46,
                                        237, 49, 193, 195, 21, 41, 142, 156, 214, 12, 143, 207, 182, 86, 221, 164, 197, 40, 23, 97, 209, 137, 25, 205, 36,
                                        90, 33, 85, 133, 6, 82, 32, 251, 71, 40, 157, 76, 52, 120, 164, 42, 51, 9, 140, 210, 45, 92, 76, 37, 7,
                                        154, 37, 98, 34, 5, 169, 145, 2, 214, 44, 52, 147, 154, 140, 51, 38, 251, 158, 28, 84, 245, 148, 55, 152, 1,
                                        29, 211, 160, 68, 65, 160, 243, 193, 109, 148, 197, 167, 101, 12, 50, 151, 84, 41, 242, 61, 28, 47, 233, 210, 143,
                                        33, 219, 215, 222, 29, 136, 238, 231, 35, 177, 150, 205, 246, 214, 45, 44, 102, 162, 146, 141, 227, 134, 78, 68, 239,
                                        153, 209, 200, 92, 33, 7, 110, 22, 183, 119, 250, 225, 106, 45, 134, 34, 83, 122, 15, 4, 218, 43, 5, 128, 32,
                                        92, 197, 41, 251, 19, 156, 23, 177, 74, 224, 153, 218, 100, 119, 1, 209, 92, 30, 254, 88, 39, 8, 49, 40, 73,
                                        42, 194, 96, 255, 53, 5, 90, 113, 202, 114, 58, 22, 154, 11, 140, 41, 14, 80, 144, 209, 20, 83, 235, 88, 13,
                                        9, 52, 201, 144, 65, 57, 201, 183, 7, 45, 246, 159, 94, 13, 76, 196, 53, 177, 156, 2, 214, 125, 239, 225, 3,
                                        46, 89, 187, 8, 77, 154, 194, 132, 98, 24, 71, 43, 221, 94, 172, 44, 153, 57, 184, 25, 154, 227, 81, 37, 149,
                                        13, 224, 64, 37, 56, 156, 165, 107, 41, 139, 87, 114, 5, 162, 69, 80, 82, 232, 141, 103, 90, 210, 66, 35, 134,
                                        208, 120, 151, 210, 153, 215, 77, 130, 197, 225, 192, 19, 100, 136, 224, 58, 44, 158, 238, 146, 60, 181, 104, 119, 133,
                                        0, 55, 55, 82, 54, 175, 212, 85, 42, 131, 197, 131, 207, 90, 255, 37, 179, 243, 167, 184, 63, 145, 59, 99, 121,
                                        200, 38, 243, 151, 135, 121, 15, 20, 197, 138, 213, 201, 9, 144, 147, 43, 66, 211, 100, 155, 122, 134, 120, 172, 10,
                                        56, 200, 73, 55, 124, 60, 99, 140, 246, 236, 92, 109, 50, 66, 220, 133, 71, 180, 223, 106, 254, 31, 226, 144, 198,
                                        240, 134, 15, 91, 183, 35, 57, 143, 133, 113, 187, 115, 229, 244, 87, 213, 178, 124, 59, 181, 212, 109, 160, 152, 22,
                                        76, 75, 154, 133, 145, 30, 118, 224, 144, 29, 72, 57, 78, 48, 14, 147, 91, 237, 245, 41, 67, 112, 239, 149, 153,
                                        181, 211, 110, 31, 117, 58, 228, 133, 71, 85, 17, 90, 174, 105, 23, 105, 180, 122, 136, 54, 45, 157, 178, 151, 18,
                                        145, 49, 104, 20, 40, 117, 90, 51, 135, 29, 37, 154, 158, 168, 138, 4, 53, 217, 149, 19, 14, 164, 244, 172, 154,
                                        9, 36, 145, 144, 102, 154, 242, 189, 101, 131, 196, 111, 108, 211, 54, 247, 253, 15, 60, 88, 143, 92, 2, 141, 5,
                                        163, 83, 61, 242, 225, 78, 6, 156, 47, 228, 69, 138, 185, 24, 48, 151, 14, 130, 26, 231, 168, 201, 49, 3, 111,
                                        43, 22, 149, 142, 116, 104, 130, 45, 65, 201, 159, 235, 180, 19, 186, 79, 177, 205, 82, 71, 24, 122, 35, 49, 123,
                                        21, 108, 185, 93, 220, 136, 74, 239, 64, 51, 180, 79, 9, 51, 10, 21, 215, 118, 181, 65, 210, 134, 75, 43, 207,
                                        5, 84, 210, 2, 231, 6, 14, 47, 210, 185, 157, 182, 166, 21, 122, 244, 75, 114, 222, 20, 66, 230, 193, 65, 204,
                                        220, 208, 163, 108, 229, 187, 114, 123, 255, 197, 220, 145, 78, 20, 36, 24, 80, 113, 158, 0 };

using namespace PNGStego::bzip2;

bool testCompress() {
	std::vector<uint8_t> temp = compress(originalData);
    return temp == bz2Data;
}

bool testDecompress() {
	std::vector<uint8_t> temp = decompress(bz2Data);
    return temp == originalData;
}

bool testWithRandomData() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<size_t> randomSize(100, 200);
    std::uniform_int_distribution<uint8_t>  randomData(0, 0xFF);


    std::vector<uint8_t> container;
    std::vector<uint8_t> compressedData;
    const int iterations = 100;
    for (int i = 0; i < iterations; ++i) {
        size_t size = randomSize(mt);
        container.resize(size);
        for (size_t i = 0; i < size; ++i) {
            container[i] = randomData(mt);
        }
        compressedData = compress(container);
        std::vector<uint8_t> decompressedData = decompress(compressedData);
        if (decompressedData != container)
            return false;
    }
    return true;
}

int main() {
	int tests = 0;
	int successes = 0;

	std::cout << "Testing compress() with precomputed data...: ";
	++tests;
	if (testCompress()) {
		std::cout << "PASSED!\n";
		++successes;
	} else {
		std::cout << "FAILED!\n";		
	}

    std::cout << "Testing decompress() with precomputed data...: ";
	++tests;
	if (testDecompress()) {
		std::cout << "PASSED!\n";
		++successes;
	} else {
		std::cout << "FAILED!\n";		
	}

	std::cout << "Testing (de-)compress() with random data...: ";
	++tests;
	if (testWithRandomData()) {
		std::cout << "PASSED!\n";
		++successes;
	} else {
		std::cout << "FAILED!\n";		
	}

	std::cout << "\nTESTS: " << tests;
	std::cout << "\nPASSED: " << successes;
	std::cout << "\nFAILED: " << tests - successes << std::endl;

	return !(successes == tests);
}