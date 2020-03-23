#!/bin/bash
DEFAULT_CFG=cfg_v2_dev_3yr
BUILD_CFGS="cfg_v4_dev_1yr:pignap_1_year_test cfg_v4_dev_3yr:pignap_3_years_test cfg_v4_prod_1yr:pignap_1_year cfg_v4_prod_3yr:pignap_3_years"

rm -rf _bin
for CFG in $BUILD_CFGS; do
    HEADER=$(echo $CFG | cut -d: -f1)
    TARGET=$(echo $CFG | cut -d: -f2)
    echo '#include "'$HEADER'.h"' > main/config/cfg_current.h
    make
    mkdir -p _bin/$TARGET/bootloader
    cp build/bootloader/bootloader.bin _bin/$TARGET/bootloader
    cp build/*.bin _bin/$TARGET
done

echo '#include "'$DEFAULT_CFG'.h"' > main/config/cfg_current.h
cd _bin
zip -r pignap.zip *
cd ..
mv _bin/pignap.zip bin
rm -rf _bin