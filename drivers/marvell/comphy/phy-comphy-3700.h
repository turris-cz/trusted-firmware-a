/*
 * Copyright (C) 2018 Marvell International Ltd.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 * https://spdx.org/licenses
 */

#ifndef PHY_COMPHY_3700_H
#define PHY_COMPHY_3700_H

#define PLL_SET_DELAY_US			600
#define COMPHY_PLL_TIMEOUT			1000
#define REG_16_BIT_MASK				0xFFFF

#define COMPHY_SELECTOR_PHY_REG			0xFC
/* bit0: 0: Lane0 is GBE0; 1: Lane1 is PCIE */
#define COMPHY_SELECTOR_PCIE_GBE0_SEL_BIT	BIT(0)
/* bit4: 0: Lane1 is GBE1; 1: Lane1 is USB3 */
#define COMPHY_SELECTOR_USB3_GBE1_SEL_BIT	BIT(4)
/* bit8: 0: Lane1 is USB, Lane2 is SATA; 1: Lane2 is USB3 */
#define COMPHY_SELECTOR_USB3_PHY_SEL_BIT	BIT(8)

/* SATA PHY register offset */
#define SATAPHY_LANE2_REG_BASE_OFFSET		0x200

/* USB3 PHY offset compared to SATA PHY */
#define USB3PHY_LANE2_REG_BASE_OFFSET		0x200

/* Comphy lane2 indirect access register offset */
#define COMPHY_LANE2_INDIR_ADDR_OFFSET		0x0
#define COMPHY_LANE2_INDIR_DATA_OFFSET		0x4

/* PHY shift to get related register address */
enum {
	PCIE = 1,
	USB3,
};

#define PCIEPHY_SHFT		2
#define USB3PHY_SHFT		2
#define PHY_SHFT(unit)		((unit == PCIE) ? PCIEPHY_SHFT : USB3PHY_SHFT)

/* PHY register */
#define COMPHY_POWER_PLL_CTRL		0x01
#define PWR_PLL_CTRL_ADDR(unit)		(COMPHY_POWER_PLL_CTRL * PHY_SHFT(unit))
#define PU_IVREF_BIT			BIT(15)
#define PU_PLL_BIT			BIT(14)
#define PU_RX_BIT			BIT(13)
#define PU_TX_BIT			BIT(12)
#define PU_TX_INTP_BIT			BIT(11)
#define PU_DFE_BIT			BIT(10)
#define RESET_DTL_RX_BIT		BIT(9)
#define PLL_LOCK_BIT			BIT(8)
#define REF_FREF_SEL_MASK		GENMASK(4, 0)
#define REF_FREF_SEL_SERDES_25MHZ	(0x1 << 0)
#define REF_FREF_SEL_SERDES_40MHZ	(0x3 << 0)
#define REF_FREF_SEL_SERDES_50MHZ	(0x4 << 0)
#define REF_FREF_SEL_PCIE_USB3_25MHZ	(0x2 << 0)
#define REF_FREF_SEL_PCIE_USB3_40MHZ	(0x3 << 0)
#define PHY_MODE_MASK			GENMASK(7, 5)
#define PHY_MODE_SATA			(0x0 << 5)
#define PHY_MODE_PCIE			(0x3 << 5)
#define PHY_MODE_SGMII			(0x4 << 5)
#define PHY_MODE_USB3			(0x5 << 5)

#define COMPHY_KVCO_CAL_CTRL		0x02
#define KVCO_CAL_CTRL_ADDR(unit)	(COMPHY_KVCO_CAL_CTRL * PHY_SHFT(unit))
#define USE_MAX_PLL_RATE_BIT		BIT(12)
#define SPEED_PLL_MASK			GENMASK(7, 2)
#define SPEED_PLL_VALUE_16		(0x10 << 2)

#define COMPHY_RESERVED_REG		0x0E
#define PHYCTRL_FRM_PIN_BIT		BIT(13)

#define COMPHY_LOOPBACK_REG0		0x23
#define DIG_LB_EN_ADDR(unit)		(COMPHY_LOOPBACK_REG0 * PHY_SHFT(unit))
#define SEL_DATA_WIDTH_MASK		GENMASK(11, 10)
#define DATA_WIDTH_10BIT		(0x0 << 10)
#define DATA_WIDTH_20BIT		(0x1 << 10)
#define DATA_WIDTH_40BIT		(0x2 << 10)
#define PLL_READY_TX_BIT		BIT(4)

#define COMPHY_SYNC_PATTERN_REG		0x24
#define SYNC_PATTERN_REG_ADDR(unit)	(COMPHY_SYNC_PATTERN_REG * \
					 PHY_SHFT(unit))
#define TXD_INVERT_BIT			BIT(10)
#define RXD_INVERT_BIT			BIT(11)

#define COMPHY_SYNC_MASK_GEN_REG	0x25
#define PHY_GEN_MAX_MASK		GENMASK(11, 10)
#define PHY_GEN_MAX_USB3_5G		(0x1 << 10)

#define COMPHY_ISOLATION_CTRL_REG	0x26
#define ISOLATION_CTRL_REG_ADDR(unit)	(COMPHY_ISOLATION_CTRL_REG * \
					 PHY_SHFT(unit))
#define PHY_ISOLATE_MODE		BIT(15)

#define COMPHY_MISC_REG0_ADDR		0x4F
#define MISC_REG0_ADDR(unit)		(COMPHY_MISC_REG0_ADDR * PHY_SHFT(unit))
#define CLK100M_125M_EN			BIT(4)
#define TXDCLK_2X_SEL			BIT(6)
#define CLK500M_EN			BIT(7)
#define PHY_REF_CLK_SEL			BIT(10)
#define MISC_REG0_DEFAULT_VALUE		0xA00D

#define COMPHY_REG_GEN2_SET_2	0x3e
#define GEN2_SETTING_2_ADDR(unit)	(COMPHY_REG_GEN2_SET_2 * PHY_SHFT(unit))
#define G2_TX_SSC_AMP_VALUE_20		BIT(14)
#define G2_TX_SSC_AMP_MASK		GENMASK(15, 9)

#define COMPHY_REG_GEN3_SET_2	0x3f
#define GEN3_SETTING_2_ADDR(unit)	(COMPHY_REG_GEN3_SET_2 * PHY_SHFT(unit))
#define G3_TX_SSC_AMP_MASK		GENMASK(15, 9)
#define G3_VREG_RXTX_MAS_ISET_MASK	GENMASK(8, 7)
#define G3_VREG_RXTX_MAS_ISET_60U	(0x0 << 7)
#define G3_VREG_RXTX_MAS_ISET_80U	(0x1 << 7)
#define G3_VREG_RXTX_MAS_ISET_100U	(0x2 << 7)
#define G3_VREG_RXTX_MAS_ISET_120U	(0x3 << 7)
#define RSVD_PH03FH_6_0_MASK		GENMASK(6, 0)

#define COMPHY_REG_UNIT_CTRL_ADDR	0x48
#define UNIT_CTRL_ADDR(unit)		(COMPHY_REG_UNIT_CTRL_ADDR * \
					 PHY_SHFT(unit))
#define IDLE_SYNC_EN			BIT(12)
#define UNIT_CTRL_DEFAULT_VALUE		0x60

#define COMPHY_MISC_REG1_ADDR		0x73
#define MISC_REG1_ADDR(unit)		(COMPHY_MISC_REG1_ADDR * PHY_SHFT(unit))
#define SEL_BITS_PCIE_FORCE		BIT(15)

#define COMPHY_REG_GEN2_SET_3		0x112
#define COMPHY_GEN_FFE_CAP_SEL_MASK	GENMASK(3, 0)
#define COMPHY_GEN_FFE_CAP_SEL_VALUE	0xF

#define COMPHY_REG_LANE_CFG0_ADDR	0x180
#define LANE_CFG0_ADDR(unit)		(COMPHY_REG_LANE_CFG0_ADDR * \
					 PHY_SHFT(unit))
#define PRD_TXDEEMPH0_MASK		BIT(0)
#define PRD_TXMARGIN_MASK		GENMASK(3, 1)
#define PRD_TXSWING_MASK		BIT(4)
#define CFG_TX_ALIGN_POS_MASK		GENMASK(8, 5)

#define COMPHY_REG_LANE_CFG1_ADDR	0x181
#define LANE_CFG1_ADDR(unit)		(COMPHY_REG_LANE_CFG1_ADDR * \
					 PHY_SHFT(unit))
#define PRD_TXDEEMPH1_MASK		BIT(15)
#define USE_MAX_PLL_RATE_EN		BIT(9)
#define TX_DET_RX_MODE			BIT(6)
#define GEN2_TX_DATA_DLY_MASK		GENMASK(4, 3)
#define GEN2_TX_DATA_DLY_DEFT		(2 << 3)
#define TX_ELEC_IDLE_MODE_EN		BIT(0)

#define COMPHY_REG_LANE_STATUS1_ADDR	0x183
#define LANE_STATUS1_ADDR(unit)		(COMPHY_REG_LANE_STATUS1_ADDR * \
					 PHY_SHFT(unit))
#define TXDCLK_PCLK_EN				BIT(0)

#define COMPHY_REG_LANE_CFG4_ADDR	0x188
#define LANE_CFG4_ADDR(unit)		(COMPHY_REG_LANE_CFG4_ADDR * \
					 PHY_SHFT(unit))
#define SPREAD_SPECTRUM_CLK_EN		BIT(7)

#define COMPHY_REG_GLOB_PHY_CTRL0_ADDR	0x1C1
#define GLOB_PHY_CTRL0_ADDR(unit)	(COMPHY_REG_GLOB_PHY_CTRL0_ADDR * \
					 PHY_SHFT(unit))
#define SOFT_RESET			BIT(0)
#define MODE_CORE_CLK_FREQ_SEL		BIT(9)
#define MODE_PIPE_WIDTH_32		BIT(3)
#define MODE_REFDIV_MASK		GENMASK(5, 4)
#define MODE_REFDIV_BY_4		(0x2 << 4)

#define COMPHY_REG_TEST_MODE_CTRL_ADDR	0x1C2
#define TEST_MODE_CTRL_ADDR(unit)	(COMPHY_REG_TEST_MODE_CTRL_ADDR * \
					 PHY_SHFT(unit))
#define MODE_MARGIN_OVERRIDE		BIT(2)

#define COMPHY_REG_GLOB_CLK_SRC_LO_ADDR	0x1C3
#define GLOB_CLK_SRC_LO_ADDR(unit)	(COMPHY_REG_GLOB_CLK_SRC_LO_ADDR * \
					 PHY_SHFT(unit))
#define MODE_CLK_SRC			BIT(0)
#define BUNDLE_PERIOD_SEL		BIT(1)
#define BUNDLE_PERIOD_SCALE		GENMASK(3, 2)
#define BUNDLE_SAMPLE_CTRL		BIT(4)
#define PLL_READY_DLY			GENMASK(7, 5)
#define CFG_SEL_20B			BIT(15)

#define COMPHY_REG_PWR_MGM_TIM1_ADDR	0x1D0
#define PWR_MGM_TIM1_ADDR(unit)		(COMPHY_REG_PWR_MGM_TIM1_ADDR * \
					 PHY_SHFT(unit))
#define CFG_PM_OSCCLK_WAIT_MASK		GENMASK(15, 12)
#define CFG_PM_RXDEN_WAIT_MASK		GENMASK(11, 8)
#define CFG_PM_RXDEN_WAIT_1_UNIT	(0x1 << 8)
#define CFG_PM_RXDLOZ_WAIT_MASK		GENMASK(7, 0)
#define CFG_PM_RXDLOZ_WAIT_7_UNIT	(0x7 << 0)
#define CFG_PM_RXDLOZ_WAIT_12_UNIT	(0xC << 0)

/* SGMII */
#define COMPHY_PHY_CFG1_OFFSET(lane)	((1 - (lane)) * 0x28)
#define PIN_PU_IVEREF_BIT		BIT(1)
#define PIN_RESET_CORE_BIT		BIT(11)
#define PIN_RESET_COMPHY_BIT		BIT(12)
#define PIN_PU_PLL_BIT			BIT(16)
#define PIN_PU_RX_BIT			BIT(17)
#define PIN_PU_TX_BIT			BIT(18)
#define PIN_TX_IDLE_BIT			BIT(19)
#define GEN_RX_SEL_MASK			GENMASK(25, 22)
#define GEN_RX_SEL_VALUE(val)		((val) << 22)
#define GEN_TX_SEL_MASK			GENMASK(29, 26)
#define GEN_TX_SEL_VALUE(val)		((val) << 26)
#define SERDES_SPEED_1_25GHZ		0x6
#define SERDES_SPEED_3_125GHZ		0x8
#define PHY_RX_INIT_BIT			BIT(30)

/* COMPHY status reg:
 * lane0: PCIe/GbE0 PHY Status 1
 * lane1: USB3/GbE1 PHY Status 1
 */
#define COMPHY_PHY_STATUS_OFFSET(lane)	(0x18 + (1 - (lane)) * 0x28)
#define PHY_RX_INIT_DONE_BIT		BIT(0)
#define PHY_PLL_READY_RX_BIT		BIT(2)
#define PHY_PLL_READY_TX_BIT		BIT(3)

#define SGMIIPHY_ADDR(off, base)	((((off) & 0x00007FF) * 2) + (base))

#define MAX_LANE_NR			3

/* comphy API */
int mvebu_3700_comphy_is_pll_locked(uint8_t comphy_index, uint32_t comphy_mode);
int mvebu_3700_comphy_power_off(uint8_t comphy_index, uint32_t comphy_mode);
int mvebu_3700_comphy_power_on(uint8_t comphy_index, uint32_t comphy_mode);
#endif /* PHY_COMPHY_3700_H */
