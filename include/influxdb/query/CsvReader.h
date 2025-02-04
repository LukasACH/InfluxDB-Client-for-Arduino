/**
 * 
 * CsvReader.h: Simple Csv parser for comma separated values, with double quotes suppport
 * 
 * MIT License
 * 
 * Copyright (c) 2020 InfluxData
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/
#ifndef _CSV_READER_
#define _CSV_READER_

#include "influxdb/query/HttpStreamScanner.h"
#include <vector>

namespace influxdb {

/**
 * CsvReader parses csv line to token by ',' (comma) character.
 * It suppports escaped  quotes, excaped comma
 **/
    class CsvReader {
    public:
        CsvReader(HttpStreamScanner *scanner);

        ~CsvReader();

        bool next();

        void close();

        std::vector<String> getRow();

        int getError() const { return _error; };
    private:
        void clearRow();

        HttpStreamScanner *_scanner = nullptr;
        std::vector<String> _row;
        int _error = 0;
    };
}
#endif //_CSV_READER_