#! /usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#
# Copyright © 2021 Libao Jin <jinlibao@outlook.com>
#
# Distributed under terms of the MIT license.

"""

"""

if __name__ == '__main__':
    n = 14
    with open('../data/game24.in', 'w') as f:
        for i in range(1, n):
            for j in range(i, n):
                for k in range(j, n):
                    for l in range(k, n):
                        # print('[{:d},{:d},{:d},{:d}]'.format(i, j, k, l))
                        print('{:d} {:d} {:d} {:d}'.format(i, j, k, l), file=f)
