/*
 * Copyright (C) 2023, Inria
 * GRAPHDECO research group, https://team.inria.fr/graphdeco
 * All rights reserved.
 *
 * This software is free for non-commercial, research and evaluation use 
 * under the terms of the LICENSE.md file.
 *
 * For inquiries contact  george.drettakis@inria.fr
 */

#ifndef CUDA_RASTERIZER_CONFIG_H_INCLUDED
#define CUDA_RASTERIZER_CONFIG_H_INCLUDED

#define NUM_CHANNELS_MAX 16
#define BLOCK_X 16
#define BLOCK_Y 16

#define DECLARE_INT_TEMPLATE_ARG_LUT(fname)                               \
    template <size_t... N>                                                \
    static constexpr auto fname##_lut(std::index_sequence<N...> s)        \
    {                                                                     \
        return std::array<decltype(&fname<0>), s.size()>{(&fname<N>)...}; \
    }

#define MAKE_INT_TEMPLATE_ARG_LUT(fname, N) \
    fname##_lut(std::make_index_sequence<N>{})

#endif