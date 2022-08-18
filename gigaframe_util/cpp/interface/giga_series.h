//
// Created by pmaxwell on 8/13/2022.
//

#ifndef GIGAFRAME_GIGASERIES_H
#define GIGAFRAME_GIGASERIES_H

class GigaSeries {
public:
    virtual unsigned long get_length() = 0;
    virtual unsigned long long get_bytes() = 0;
};

/**
 * A static GigaSeries actually holds the data itself. It is a
 * store of data, and cannot be resized.
 */
class StaticGigaSeries : public GigaSeries {
public:
    unsigned long get_length() override {
        // NOTE: temp code for scaffolding & building purposes
        return 0;
    }
    unsigned long long get_bytes() override {
        // NOTE: temp code for scaffolding & building purposes
        return 0;
    }
};

/**
 * A wrapper GigaSeries is a thin interface that may present as a
 * normal GigaSeries, but in reality holds no data, only pointers
 * to the data. It is a thin wrapper on top of the underlying data.
 */
class WrapperGigaSeries : public GigaSeries {

};

class FrameWrapperGigaSeries : public WrapperGigaSeries {

};


/**
 * Fast search is a shared-memory multi-core HPC-style search applied over a GigaSeries.
 */
void fast_search(const GigaSeries& giga_series) {

}

/**
 * Fast apply is a shared-memory HPC-style search applied over a GigaSeries.
 */
void fast_apply(GigaSeries& giga_series) {

}

#endif //GIGAFRAME_GIGASERIES_H
