#!/bin/bash
#  Copyright (C) 2018-2020 LEIDOS.
# 
#  Licensed under the Apache License, Version 2.0 (the "License"); you may not
#  use this file except in compliance with the License. You may obtain a copy of
#  the License at
# 
#  http://www.apache.org/licenses/LICENSE-2.0
# 
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
#  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
#  License for the specific language governing permissions and limitations under
#  the License.

# script to run tests, generate test-coverage, and store coverage reports in a place
# easily accessible to sonar. Test names should follow convention run<pluginName>Tests

set -x
for d in v2i-hub/*
do
    echo ""
    echo $d
    if [[ -d $d ]]; then
        if ls $d | grep run[a-zA-Z]*Tests ; then
            TESTS="./`ls $d | grep run[a-zA-Z]*Tests`"
            echo "$TESTS built"
            cd $d
            $TESTS
            gcovr -k .
            mkdir coverage
            PLUGIN=`echo $d | cut -d "/" -f 2`
            mv $(ls | grep [a-zA-Z0-9#-]*$PLUGIN | grep -v test#  | grep gcov) coverage
            cd ../..
        else
            echo "no tests built"
        fi
    fi
done