//
//  log-rotator-schedule-test.h
//  Residue
//
//  Copyright 2017-present Muflihun Labs
//
//  Author: @abumusamq
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#ifndef LOG_ROTATOR_SCHEDULE_TEST_H
#define LOG_ROTATOR_SCHEDULE_TEST_H

#include "test.h"
#include "src/utils/utils.h"
#include "src/tasks/log-rotator.h"

using namespace residue;

TEST(LogRotatorScheduleTest, HourlyRoundOffCalculation)
{
    TestData<int, unsigned long> TData = {
        { 1517579594, 406 },   //  Fri, 02/Feb/2018 00:53:14
        { 1517570594, 2206 },  //  Fri, 02/Feb/2018 22:23:14
        { 1517608394, 406 }, //  Sat, 03/Feb/2018 08:53:14
        { 1517626395, 405 }, //  Sat, 03/Feb/2018 13:53:14
    };

    for (auto& item : TData) {
        HourlyLogRotator logRotator(nullptr);

        ASSERT_EQ(item.get<1>(), logRotator.calculateRoundOff(item.get<0>()));
    }
}

TEST(LogRotatorScheduleTest, SixHoursRoundOffCalculation)
{
    TestData<int, unsigned long> TData = {
        { 1517570594, 5806  }, // Fri, 02/Feb/2018 22:23:14
        { 1517579594, 18406 }, //  Sat, 03/Feb/2018 00:53:14
        { 1517608394, 11206 }, //  Sat, 03/Feb/2018 08:53:14
        { 1517626394, 14806 }, //  Sat, 03/Feb/2018 13:53:14
    };

    for (auto& item : TData) {
        SixHoursLogRotator logRotator(nullptr);

        ASSERT_EQ(item.get<1>(), logRotator.calculateRoundOff(item.get<0>()));
    }
}

TEST(LogRotatorScheduleTest, TwelveHoursRoundOffCalculation)
{
    TestData<int, unsigned long> TData = {
        { 1517570594, 5806  }, // Fri, 02/Feb/2018 22:23:14
        { 1517579594, 40006 }, //  Sat, 03/Feb/2018 00:53:14
        { 1517608394, 11206 }, //  Sat, 03/Feb/2018 08:53:14
        { 1517626394, 36406 }, //  Sat, 03/Feb/2018 13:53:14
    };

    for (auto& item : TData) {
        TwelveHoursLogRotator logRotator(nullptr);

        ASSERT_EQ(item.get<1>(), logRotator.calculateRoundOff(item.get<0>()));
    }
}

TEST(LogRotatorScheduleTest, DailyRoundOffCalculation)
{
    TestData<int, unsigned long> TData = {
        { 1517570594, 5806  }, // Fri, 02/Feb/2018 22:23:14
        { 1517579594, 83206 }, //  Sat, 03/Feb/2018 00:53:14
        { 1517608394, 54406 }, //  Sat, 03/Feb/2018 08:53:14
        { 1517626394, 36406 }, //  Sat, 03/Feb/2018 13:53:14
    };

    for (auto& item : TData) {
        DailyLogRotator logRotator(nullptr);

        ASSERT_EQ(item.get<1>(), logRotator.calculateRoundOff(item.get<0>()));
    }
}

TEST(LogRotatorScheduleTest, WeeklyRoundOffCalculation)
{
    TestData<int, unsigned long, std::string> TData = {
        //             days in
        //            until next
        //              monday
        { 1517570594, (2*86400) + 5806, "Fri, 02/Feb/2018 22:23:14" },
        { 1517635888, (1*86400) + 26912, "Sat, 03/Feb/2018 16:31:28" },
        { 1517746897, (0*86400) + 2303, "Sun, 04/Feb/2018 23:21:37" },
        { 1517833297, (6*86400) + 2303, "Mon, 05/Feb/2018 23:21:37" },
        { 1517919697, (5*86400) + 2303, "Tue, 06/Feb/2018 23:21:37" },
        { 1518006097, (4*86400) + 2303, "Wed, 07/Feb/2018 23:21:37" },
        { 1518092497, (3*86400) + 2303, "Thu, 08/Feb/2018 23:21:37" },
    };

    for (auto& item : TData) {
        WeeklyLogRotator logRotator(nullptr);

        ASSERT_EQ(item.get<1>(), logRotator.calculateRoundOff(item.get<0>())) << item.get<2>();
    }
}

TEST(LogRotatorScheduleTest, MonthlyRoundOffCalculation)
{
    TestData<int, unsigned long, std::string> TData = {
        //             days in
        //            next month
        { 1517570594, (26*86400) + 5806, "Fri, 02/Feb/2018 22:23:14"  },
        { 1519734097, (1*86400) + 2303, "Tue, 27/Feb/2018 23:21:37" },
        { 1519820497, (0*86400) + 2303, "Wed, 28/Feb/2018 23:21:37" },
        { 1582892497, (1*86400) + 2303, "Fri, 28/Feb/2020 23:21:37 - leap year" },
        { 1520252497, (26*86400) + 2303, "Mon, 05/Mar/2018 23:21:37" },
        { 1522412497, (1*86400) + 2303, "Fri, 30/Mar/2018 23:21:37" },
        { 1522326097, (2*86400) + 2303, "Thu, 29/Mar/2018 23:21:37" },
        { 1522498897, (0*86400) + 2303, "Sat, 31/Mar/2018 23:21:37" },
        { 1525094497, (0*86400) + 2303, "Mon, 30/Apr/2018 23:21:37 "},
        { 1525008097, (1*86400) + 2303, "Sun, 29/Apr/2018 23:21:37 "},
        { 1519906897, (30*86400) + 2303, "Thu, 01/Mar/2018 23:21:37" },
        { 1530451297, (30*86400) + 2303, "Sun, 01/Jul/2018 23:21:37" },
        { 1532956897, (1*86400) + 2303, "Mon, 30/Jul/2018 23:21:37" },
        { 1533043297, (0*86400) + 2303, "Tue, 31/Jul/2018 23:21:37" },
    };

    for (auto& item : TData) {
        MonthlyLogRotator logRotator(nullptr);

        ASSERT_EQ(item.get<1>(), logRotator.calculateRoundOff(item.get<0>())) << item.get<2>();
    }
}

TEST(LogRotatorScheduleTest, YearlyRoundOffCalculation)
{
    TestData<int, unsigned long> TData = {
        { 1546172497, 88703 }, //  Mon, 30/Dec/2018 23:21:37
        { 1546258897, 2303 }, //  Mon, 31/Dec/2018 23:21:37
        { 1517570594, 28690606  }, // Fri, 02/Feb/2018 22:23:14
        { 1546345297, 31365503 }, //  Tue, 01/Jan/2019 23:21:37
    };

    for (auto& item : TData) {
        YearlyLogRotator logRotator(nullptr);

        ASSERT_EQ(item.get<1>(), logRotator.calculateRoundOff(item.get<0>()));
    }
}

#endif // LOG_ROTATOR_SCHEDULE_TEST_H
