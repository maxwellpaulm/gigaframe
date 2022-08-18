#!/usr/bin/env python3
if __name__ == "__main__":
    # import the C++ extension module
    from gigaframe_util.giga_series import GigaSeries

    # create a giga series object
    giga_series = GigaSeries()

    # print length
    print(f"GigaSeries Length: {giga_series.get_length()}")

    # print bytes
    print(f"GigaSeries Bytes: {giga_series.get_bytes()}")
