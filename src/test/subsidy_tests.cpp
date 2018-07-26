// Copyright (c) 2014-2018 The Dash Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "validation.h"

#include "test/test_zeroone.h"

#include <boost/test/unit_test.hpp>

BOOST_FIXTURE_TEST_SUITE(subsidy_tests, TestingSetup)

BOOST_AUTO_TEST_CASE(block_subsidy_test)
{
    const Consensus::Params& consensusParams = Params(CBaseChainParams::MAIN).GetConsensus();

    uint32_t nPrevBits;
    int32_t nPrevHeight;
    CAmount nSubsidy;

    // details for block 4249 (subsidy returned will be for block 4250)
    nPrevBits = 0x1c4a47c4;
    nPrevHeight = 262770;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 2600000000ULL);

    // details for block 4501 (subsidy returned will be for block 4502)
    nPrevBits = 0x1c4a47c4;
    nPrevHeight = 262801;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 2383333334ULL);

    // details for block 5464 (subsidy returned will be for block 5465)
    nPrevBits = 0x1c29ec00;
    nPrevHeight = 525599;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 2383333334ULL);

    // details for block 5465 (subsidy returned will be for block 5466)
    nPrevBits = 0x1c29ec00;
    nPrevHeight = 525601;
    nSubsidy = GetBlockSubsidy(nPrevBits, nPrevHeight, consensusParams, false);
    BOOST_CHECK_EQUAL(nSubsidy, 2184722223ULL);
}

BOOST_AUTO_TEST_SUITE_END()
