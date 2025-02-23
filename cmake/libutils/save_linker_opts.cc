/*
 * Copyright (c) 2019, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0, as
 * published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms,
 * as designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an
 * additional permission to link the program and your derivative works
 * with the separately licensed software that they have included with
 * MySQL.
 *
 * Without limiting anything contained in the foregoing, this file,
 * which is part of MySQL Connector/C++, is also subject to the
 * Universal FOSS Exception, version 1.0, a copy of which can be found at
 * http://oss.oracle.com/licenses/universal-foss-exception.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 */

#include <iostream>
#include <fstream>
#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <direct.h>
#endif
using namespace std;

int main(int argc, char* argv[])
{
	char pwd[1024];
#ifdef __linux__
	if (!getcwd(pwd, sizeof(pwd)))
#elif _WIN32
	if (!_getcwd(pwd, sizeof(pwd)))
#endif
		return 1;

	//cout << "Got " << argc << " arguments" << endl;
	//cout << "Output file: " << argv[1] << endl;
	//cout << "pwd: " << pwd << endl;

	ofstream out(argv[1]);

	// Note: first line in the output is the working directory

	out << pwd << endl;

	// Note: argv[2] is the compiler/linker command

	for (unsigned pos = 3; pos < argc; pos++)
	{
		if (string(argv[pos]) == "-o")
		{
			pos++;
			continue;
		}

		//cout << "-- opt: " << argv[pos] << endl;
		out << argv[pos] << endl;
	}
	out.flush();
	return 0;
}
