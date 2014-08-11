//
//  LinguisticSignalSystem.c
//  LinguisticSignalSystem
//
//  Created by Eli Hutton on 8/11/14.
//  Copyright (c) 2014 SwatchXNU. All rights reserved.
//

#include <mach/mach_types.h>

kern_return_t LinguisticSignalSystem_start(kmod_info_t * ki, void *d);
kern_return_t LinguisticSignalSystem_stop(kmod_info_t *ki, void *d);

kern_return_t LinguisticSignalSystem_start(kmod_info_t * ki, void *d)
{
    return KERN_SUCCESS;
}

kern_return_t LinguisticSignalSystem_stop(kmod_info_t *ki, void *d)
{
    return KERN_SUCCESS;
}
