//
// Created by pmaxwell on 8/13/2022.
//

#ifndef GIGAFRAME_GIGAFRAME_H
#define GIGAFRAME_GIGAFRAME_H

#include "giga_series.h"
#include "types.h"

class GigaFrame {
public:
    virtual IndexType get_rows() = 0;
    virtual IndexType get_cols() = 0;
    virtual SizeType get_bytes() = 0;

    template<class T>
    virtual T get_obj(IndexType row, IndexType col) = 0;

    virtual GigaSeries get_col_series(IndexType col) = 0;
    virtual GigaSeries get_row_series(IndexType row) = 0;

    void add_giga_index(std::shared_ptr<GigaIndex> giga_index_ptr);
};

class StaticGigaFrame : public GigaFrame {
private:
    GigaSeries* giga_series_array;
    SizeType bytes_size;
    IndexType num_cols;
    IndexType num_rows;
public:
    StaticGigaFrame(GigaSeries* giga_series_array, IndexType num_cols, IndexType num_rows);
};

#endif //GIGAFRAME_GIGAFRAME_H
