%LUT1D - F16
u16ShamOffset = 3;
pf16Table = (2^15-1)*[0.0999786370433668,0.199987792596210,0.299996948149052,0.255989257484664,0.288979766228217,0.310983611560411,0.411999877925962,0.468001342814417,0.246986297189245,0.122989593188269,0,-0.144993438520463,-0.234992522965178,-0.589007232886746,0.666005432294687,0.788995025482955,0.818994720297861];
s16MidIdx = 1;

%LUT1D - F32
u32ShamOffset = 3;
pf32Table = (2^31-1)*[0.0999786370433668,0.199987792596210,0.299996948149052,0.255989257484664,0.288979766228217,0.310983611560411,0.411999877925962,0.468001342814417,0.246986297189245,0.122989593188269,0,-0.144993438520463,-0.234992522965178,-0.589007232886746,0.666005432294687,0.788995025482955,0.818994720297861];
s32MidIdx = 1;

%LUT1D - FLT
pfltTable = [0.0999786370433668,0.199987792596210,0.299996948149052,0.255989257484664,0.288979766228217,0.310983611560411,0.411999877925962,0.468001342814417,0.246986297189245,0.122989593188269,0,-0.144993438520463,-0.234992522965178,-0.589007232886746,0.666005432294687,0.788995025482955,0.818994720297861];

%LUT2D - F16
u16ShamOffset1 = 3;
u16ShamOffset2 = 3;
pf16Table2 = (2^15-1)*[0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317];
s16MidIdx2 = 1;

%LUT2D - F32
u32ShamOffset1 = 3;
u32ShamOffset2 = 3;
pf32Table2 = (2^31-1)*[0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317];
s32MidIdx2 = 1;

%LUT2D - FLT
pfltTable2 = [0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317,0.149998474074526,0.199987792596210,0.250007629627369,0.299996948149052,0.349986266670736,0.400006103701895,0.449995422223579,0.500015259254738,0.550004577776421,0.599993896298105,0.650013733329264,0.700003051850948,0.750022888882107,0.800012207403790,0.850001525925474,0.900021362956633,0.950010681478317];