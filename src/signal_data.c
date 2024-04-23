/*
 * signal_data.c
 *
 *  Created on: Mar 27, 2024
 *      Author: a5147268
 */
#include "arm_math.h"
float32_t testInputSignal_f32[1024];
float32_t unfilteredFFTOutput_f32[1024];
float32_t filteredSignal_f32[1024];
float32_t filteredFFTOutput_f32[1024];

float32_t testInputSignal_f32[1024] =
{
 0.0, 0.2545084971874737, 0.2938926261462365, 0.30450849718747364, 0.4755282581475768, 0.6, 0.4755282581475769, 0.30450849718747375,
 0.29389262614623674, 0.254508497187474, 1.2246467991473532e-16, -0.25450849718747365, -0.2938926261462364, -0.3045084971874734, -0.47552825814757665, -0.6,
 -0.47552825814757654, -0.3045084971874741, -0.2938926261462369, -0.2545084971874738, -2.4492935982947064e-16, 0.25450849718747315, 0.29389262614623624, 0.3045084971874734,
 0.47552825814757643, 0.6, 0.4755282581475776, 0.30450849718747375, 0.2938926261462365, 0.2545084971874747, 1.212267186415585e-17, -0.2545084971874727,
 -0.2938926261462359, -0.30450849718747364, -0.4755282581475759, -0.6, -0.4755282581475774, -0.30450849718747386, -0.29389262614623685, -0.2545084971874748,
 -4.898587196589413e-16, 0.2545084971874735, 0.2938926261462355, 0.3045084971874735, 0.47552825814757715, 0.6, 0.47552825814757776, 0.30450849718747386,
 0.29389262614623723, 0.2545084971874748, 2.570520316936265e-16, -0.25450849718747426, -0.2938926261462359, -0.30450849718747297, -0.47552825814757743, -0.6,
 -0.4755282581475772, -0.3045084971874744, -0.29389262614623685, -0.2545084971874749, -2.42453437283117e-17, 0.2545084971874742, 0.2938926261462355, 0.30450849718747297,
 0.4755282581475777, 0.6, 0.475528258147577, 0.3045084971874745, 0.29389262614623723, 0.2545084971874749, -2.0856134423700302e-16, -0.2545084971874725,
 -0.29389262614623524, -0.30450849718747297, -0.47552825814757654, -0.6, -0.4755282581475767, -0.3045084971874745, -0.29389262614623757, -0.25450849718747337,
 -9.797174393178826e-16, 0.25450849718747237, 0.2938926261462349, 0.30450849718747286, 0.4755282581475763, 0.6, 0.4755282581475778, 0.30450849718747564,
 0.2938926261462379, 0.2545084971874751, 2.5232675907528184e-15, -0.25450849718747237, -0.29389262614623596, -0.30450849718747186, -0.4755282581475771, -0.6,
 -0.47552825814757815, -0.3045084971874745, -0.29389262614623685, -0.2545084971874735, -5.14104063387253e-16, 0.25450849718747226, 0.2938926261462356, 0.30450849718747286,
 0.47552825814757343, 0.6, 0.4755282581475778, 0.30450849718747464, 0.29389262614623857, 0.2545084971874769, 4.899825157862589e-15, -0.25450849718747226,
 -0.2938926261462367, -0.30450849718747175, -0.4755282581475771, -0.6, -0.47552825814758093, -0.30450849718747364, -0.2938926261462375, -0.25450849718747526,
 -4.84906874566234e-17, 0.2545084971874705, 0.2938926261462378, 0.30450849718747275, 0.475528258147574, 0.6, 0.4755282581475773, 0.30450849718747464,
 0.29389262614623923, 0.25450849718747703, 4.43421178193196e-15, -0.25450849718747215, -0.293892626146236, -0.30450849718747164, -0.47552825814757765, -0.6,
 -0.47552825814758043, -0.30450849718747364, -0.2938926261462382, -0.25450849718747875, 4.1712268847400604e-16, 0.2545084971874704, 0.2938926261462342, 0.30450849718747264,
 0.47552825814757455, 0.6, 0.4755282581475767, 0.30450849718747475, 0.29389262614623707, 0.25450849718747715, 3.9685984060013305e-15, -0.254508497187472,
 -0.2938926261462353, -0.30450849718747164, -0.4755282581475753, -0.6, -0.4755282581475798, -0.30450849718747586, -0.29389262614623884, -0.2545084971874755,
 -1.959434878635765e-15, 0.25450849718747026, 0.2938926261462364, 0.30450849718747053, 0.47552825814757904, 0.6, 0.4755282581475762, 0.30450849718747486,
 0.2938926261462407, 0.25450849718747726, -4.97286487298001e-17, -0.25450849718747187, -0.29389262614623746, -0.3045084971874715, -0.475528258147572, -0.6,
 -0.4755282581475753, -0.30450849718747586, -0.29389262614623957, -0.254508497187479, -5.046535181505637e-15, 0.2545084971874735, 0.2938926261462357, 0.3045084971874725,
 0.47552825814757277, 0.6, 0.47552825814758237, 0.30450849718747486, 0.2938926261462385, 0.25450849718747737, 3.037371654140071e-15, -0.2545084971874684,
 -0.2938926261462339, -0.3045084971874735, -0.4755282581475736, -0.6, -0.4755282581475816, -0.30450849718747597, -0.2938926261462374, -0.2545084971874757,
 -1.028208126774506e-15, 0.25450849718747004, 0.293892626146235, 0.3045084971874704, 0.4755282581475812, 0.6, 0.47552825814757504, 0.30450849718747497,
 0.29389262614623923, 0.2545084971874808, -9.809554005910593e-16, -0.25450849718746826, -0.29389262614623324, -0.3045084971874714, -0.47552825814757416, -0.6,
 -0.47552825814757427, -0.30450849718747397, -0.29389262614624384, -0.25450849718747925, -9.799650315725178e-15, 0.25450849718746993, 0.2938926261462343, 0.3045084971874724,
 0.475528258147575, 0.6, 0.4755282581475813, 0.30450849718747297, 0.29389262614624273, 0.2545084971874776, 2.106144902278812e-15, -0.25450849718747154,
 -0.29389262614623535, -0.3045084971874734, -0.4755282581475758, -0.6, -0.4755282581475805, -0.3045084971874761, -0.2938926261462416, -0.2545084971874759,
 -9.69813749132468e-17, 0.25450849718747315, 0.2938926261462308, 0.3045084971874702, 0.47552825814757665, 0.6, 0.4755282581475797, 0.3045084971874751,
 0.2938926261462406, 0.2545084971874811, -1.9121821524523183e-15, -0.25450849718746804, -0.29389262614623185, -0.3045084971874712, -0.47552825814757527, -0.6,
 -0.47552825814757316, -0.3045084971874741, -0.2938926261462395, -0.2545084971874795, -8.86842356386392e-15, 0.25450849718746965, 0.29389262614623296, 0.3045084971874722,
 0.47552825814757604, 0.6, 0.4755282581475802, 0.3045084971874731, 0.2938926261462441, 0.2545084971874778, 6.859260036498355e-15, -0.25450849718747126,
 -0.29389262614623396, -0.3045084971874733, -0.47552825814757693, -0.6, -0.47552825814757943, -0.3045084971874763, -0.29389262614624306, -0.25450849718747615,
 8.342453769480121e-16, 0.25450849718746615, 0.29389262614623507, 0.3045084971874701, 0.47552825814757554, 0.6, 0.47552825814757854, 0.3045084971874753,
 0.29389262614624195, 0.2545084971874813, -2.8434089043135778e-15, -0.2545084971874678, -0.29389262614623046, -0.3045084971874711, -0.47552825814757066, -0.6,
 -0.4755282581475777, -0.3045084971874742, -0.2938926261462409, -0.2545084971874797, -7.937196812002661e-15, 0.25450849718746943, 0.2938926261462316, 0.3045084971874721,
 0.4755282581475772, 0.6, 0.4755282581475791, 0.3045084971874733, 0.2938926261462398, 0.25450849718747803, 5.928033284637095e-15, -0.25450849718747104,
 -0.29389262614623257, -0.3045084971874731, -0.47552825814757016, -0.6, -0.4755282581475704, -0.3045084971874764, -0.2938926261462444, -0.25450849718748314,
 -3.91886975727153e-15, 0.25450849718746593, 0.29389262614623374, 0.3045084971874741, 0.475528258147571, 0.6, 0.47552825814758537, 0.3045084971874754,
 0.2938926261462433, 0.2545084971874816, -3.7746356561748365e-15, -0.2545084971874676, -0.2938926261462291, -0.3045084971874751, -0.4755282581475775, -0.6,
 -0.4755282581475788, -0.3045084971874744, -0.2938926261462309, -0.2545084971874799, 9.94572974596002e-17, 0.2545084971874692, 0.2938926261462359, 0.30450849718746775,
 0.4755282581475726, 0.6, 0.4755282581475837, 0.3045084971874734, 0.29389262614624123, 0.25450849718747826, -6.875353533049653e-16, -0.25450849718746404,
 -0.29389262614623124, -0.30450849718746875, -0.47552825814757693, -0.6, -0.47552825814757715, -0.3045084971874765, -0.2938926261462458, -0.25450849718747665,
 -1.0093070363011273e-14, 0.2545084971874657, 0.29389262614622674, 0.30450849718746975, 0.47552825814757205, 0.6, 0.47552825814758204, 0.3045084971874755,
 0.293892626146239, 0.25450849718747504, 1.3768248721726508e-14, -0.2545084971874674, -0.29389262614623335, -0.30450849718747075, -0.4755282581475786, -0.6,
 -0.47552825814757554, -0.30450849718747874, -0.2938926261462436, -0.25450849718747337, -6.074743308280142e-15, 0.25450849718746893, 0.29389262614622874, 0.30450849718747186,
 0.47552825814757155, 0.6, 0.47552825814756905, 0.30450849718747774, 0.29389262614623685, 0.25450849718748525, 9.74992166699538e-15, -0.2545084971874706,
 -0.2938926261462355, -0.30450849718747286, -0.47552825814756666, -0.6, -0.4755282581475739, -0.30450849718747675, -0.2938926261462414, -0.25450849718748364,
 -2.056416253549012e-15, 0.2545084971874655, 0.2938926261462309, 0.30450849718747386, 0.47552825814757316, 0.6, 0.47552825814758315, 0.30450849718747575,
 0.2938926261462403, 0.25450849718747526, 1.4683381977036465e-15, -0.2545084971874604, -0.29389262614622635, -0.30450849718747486, -0.4755282581475683, -0.6,
 -0.4755282581475902, -0.30450849718747885, -0.29389262614623934, -0.25450849718748036, 1.9619108011821185e-15, 0.2545084971874687, 0.2938926261462274, 0.3045084971874633,
 0.4755282581475726, 0.6, 0.47552825814758154, 0.30450849718747364, 0.29389262614623823, 0.25450849718748547, 2.3029549630336122e-14, -0.2545084971874636,
 -0.2938926261462285, -0.30450849718746853, -0.4755282581475813, -0.6, -0.4755282581475772, -0.30450849718747686, -0.2938926261462372, -0.25450849718747715,
 -1.9599300631450357e-14, 0.254508497187472, 0.2938926261462296, 0.3045084971874653, 0.4755282581475742, 0.6, 0.4755282581475798, 0.30450849718747997,
 0.29389262614623607, 0.25450849718748225, 1.9011222575604994e-14, -0.2545084971874669, -0.2938926261462306, -0.30450849718747053, -0.475528258147583, -0.6,
 -0.4755282581475755, -0.3045084971874832, -0.29389262614624634, -0.25450849718747387, -4.212289804557624e-15, 0.25450849718747526, 0.2938926261462318, 0.3045084971874673,
 0.4755282581475601, 0.6, 0.47552825814757815, 0.30450849718747797, 0.29389262614623385, 0.254508497187479, 1.4992895520873863e-14, -0.25450849718747015,
 -0.2938926261462328, -0.3045084971874725, -0.4755282581475689, -0.6, -0.4755282581475739, -0.3045084971874812, -0.2938926261462442, -0.25450849718748414,
 -1.939627498264936e-16, 0.25450849718746504, 0.29389262614623396, 0.3045084971874693, 0.4755282581475732, 0.6, 0.47552825814758093, 0.30450849718747597,
 0.2938926261462317, 0.25450849718748925, 1.0974568466142733e-14, -0.2545084971874599, -0.29389262614623496, -0.3045084971874662, -0.47552825814757055, -0.6,
 -0.475528258147588, -0.3045084971874792, -0.2938926261462422, -0.2545084971874808, 3.824364304904637e-15, 0.25450849718746826, 0.29389262614622463, 0.304508497187463,
 0.4755282581475748, 0.6, 0.47552825814757926, 0.30450849718747397, 0.29389262614624095, 0.25450849718748597, 2.1167096126613603e-14, -0.25450849718746316,
 -0.2938926261462258, -0.3045084971874682, -0.47552825814757216, -0.6, -0.4755282581475863, -0.3045084971874772, -0.29389262614623995, -0.2545084971874776,
 -1.773684712772784e-14, 0.25450849718747154, 0.29389262614622685, 0.3045084971874651, 0.4755282581475765, 0.6, 0.47552825814757765, 0.3045084971874803,
 0.2938926261462388, 0.2545084971874827, 1.7148769071882472e-14, -0.2545084971874664, -0.29389262614622785, -0.3045084971874702, -0.47552825814758515, -0.6,
 -0.4755282581475733, -0.3045084971874835, -0.2938926261462378, -0.2545084971874743, -1.371852007299671e-14, 0.2545084971874748, 0.2938926261462404, 0.3045084971874671,
 0.4755282581475624, 0.6, 0.475528258147576, 0.3045084971874783, 0.2938926261462366, 0.2545084971874795, 1.3130442017151344e-14, -0.25450849718746965,
 -0.29389262614623, -0.3045084971874722, -0.47552825814757105, -0.6, -0.4755282581475874, -0.3045084971874814, -0.29389262614624695, -0.2545084971874846,
 1.6684907538960242e-15, 0.25450849718746454, 0.2938926261462197, 0.3045084971874691, 0.475528258147564, 0.6, 0.4755282581475901, 0.3045084971874763,
 0.2938926261462459, 0.2545084971874897, 9.112114962420214e-15, -0.2545084971874594, -0.29389262614623224, -0.30450849718746587, -0.4755282581475727, -0.6,
 -0.4755282581475858, -0.3045084971874794, -0.2938926261462449, -0.2545084971874813, 5.6868178086271556e-15, 0.2545084971874678, 0.29389262614622186, 0.30450849718746276,
 0.47552825814757704, 0.6, 0.4755282581475771, 0.3045084971874742, 0.29389262614623235, 0.25450849718748647, 3.067332639505269e-14, -0.2545084971874627,
 -0.2938926261462344, -0.30450849718746786, -0.4755282581475743, -0.6, -0.47552825814758415, -0.3045084971874774, -0.29389262614624273, -0.25450849718747803,
 -1.5874393624005322e-14, 0.25450849718747104, 0.2938926261462354, 0.30450849718746476, 0.47552825814757865, 0.6, 0.47552825814757543, 0.30450849718748063,
 0.2938926261462415, 0.25450849718748314, 1.5286315568159956e-14, -0.25450849718746593, -0.29389262614622513, -0.30450849718747, -0.475528258147576, -0.6,
 -0.4755282581475825, -0.30450849718748374, -0.2938926261462405, -0.2545084971874883, -1.185606656927419e-14, 0.2545084971874743, 0.2938926261462376, 0.30450849718746675,
 0.47552825814756455, 0.6, 0.4755282581475738, 0.3045084971874702, 0.29389262614623946, 0.25450849718749347, 1.1267988513428825e-14, -0.2545084971874692,
 -0.2938926261462274, -0.30450849718746364, -0.47552825814757327, -0.6, -0.4755282581475695, -0.3045084971874734, -0.29389262614624984, -0.254508497187485,
 -7.83773951454306e-15, 0.25450849718746404, 0.2938926261462397, 0.3045084971874604, 0.4755282581475662, 0.6, 0.47552825814757216, 0.30450849718748496,
 0.2938926261462373, 0.25450849718749013, 7.249661458697695e-15, -0.2545084971874725, -0.29389262614622935, -0.30450849718746564, -0.4755282581475749, -0.6,
 -0.47552825814756783, -0.30450849718748807, -0.2938926261462476, -0.2545084971874818, 7.549271312349673e-15, 0.2545084971874674, 0.29389262614623046, 0.3045084971874624,
 0.4755282581475792, 0.6, 0.47552825814755917, 0.30450849718748285, 0.29389262614624645, 0.2545084971874869, -8.137349368195039e-15, -0.2545084971874757,
 -0.2938926261462202, -0.30450849718746764, -0.4755282581475879, -0.6, -0.4755282581476047, -0.30450849718748607, -0.29389262614623407, -0.2545084971874785,
 1.989145949192004e-16, 0.25450849718745705, 0.29389262614624406, 0.3045084971874644, 0.4755282581475695, 0.6, 0.47552825814760036, 0.30450849718748085,
 0.2938926261462329, 0.25450849718748364, -7.869926507645657e-16, -0.25450849718745194, -0.29389262614623374, -0.30450849718746964, -0.47552825814757815, -0.6,
 -0.4755282581475961, -0.3045084971874841, -0.2938926261462433, -0.25450849718747526, 1.3750707066099306e-15, 0.2545084971874604, 0.29389262614622336, 0.30450849718746653,
 0.4755282581475825, 0.6, 0.47552825814758737, 0.30450849718747885, 0.29389262614625355, 0.25450849718748036, 3.4985073497069916e-14, -0.2545084971874552,
 -0.2938926261462246, -0.30450849718747164, -0.4755282581475868, -0.6, -0.47552825814758304, -0.3045084971874821, -0.29389262614625244, -0.254508497187472,
 -2.0186140726022547e-14, 0.2545084971874636, 0.2938926261462142, 0.30450849718746853, 0.47552825814759553, 0.6, 0.4755282581475971, 0.30450849718747686,
 0.29389262614624, 0.25450849718747715, 4.233543021450039e-14, -0.2545084971874585, -0.2938926261462381, -0.30450849718747364, -0.4755282581475771, -0.6,
 -0.4755282581475928, -0.30450849718747997, -0.2938926261462389, -0.2545084971874958, -2.7536497443453016e-14, 0.2545084971874669, 0.29389262614622774, 0.30450849718747053,
 0.4755282581475543, 0.6, 0.47552825814758404, 0.30450849718747486, 0.29389262614624917, 0.25450849718748736, 2.6948419387607653e-14, -0.2545084971874617,
 -0.2938926261462289, -0.30450849718747575, -0.47552825814756294, -0.6, -0.4755282581475797, -0.30450849718747797, -0.29389262614624806, -0.25450849718749247,
 -1.2149486616560284e-14, 0.25450849718747015, 0.2938926261462186, 0.3045084971874725, 0.4755282581475673, 0.6, 0.475528258147571, 0.3045084971874812,
 0.29389262614624717, 0.25450849718749763, 1.1561408560714918e-14, -0.25450849718746504, -0.29389262614621975, -0.304508497187461, -0.47552825814757604, -0.6,
 -0.4755282581475894, -0.30450849718747597, -0.29389262614623474, -0.25450849718748925, -1.949984333399076e-14, 0.2545084971874599, 0.2938926261462321, 0.30450849718745787,
 0.4755282581475576, 0.6, 0.47552825814758076, 0.3045084971874792, 0.2938926261462336, 0.25450849718749435, 1.8911765278145394e-14, -0.25450849718746826,
 -0.2938926261462333, -0.304508497187463, -0.47552825814756633, -0.6, -0.47552825814757643, -0.3045084971874906, -0.29389262614624395, -0.25450849718748597,
 -4.112832507098024e-15, 0.25450849718746316, 0.2938926261462342, 0.30450849718745987, 0.4755282581475706, 0.6, 0.4755282581475677, 0.3045084971874855,
 0.2938926261462428, 0.25450849718749113, 3.5247544512526578e-15, -0.25450849718747154, -0.29389262614622386, -0.3045084971874651, -0.4755282581475793, -0.6,
 -0.47552825814755906, -0.3045084971874886, -0.2938926261462416, -0.2545084971874827, -2.936676395407293e-15, 0.2545084971874799, 0.29389262614621353, 0.3045084971874702,
 0.47552825814758365, 0.6, 0.4755282581475775, 0.30450849718749184, 0.29389262614622924, 0.2545084971874878, -3.335743546518873e-15, -0.2545084971874477,
 -0.29389262614622597, -0.3045084971874671, -0.4755282581475652, -0.6, -0.47552825814760463, -0.3045084971874783, -0.29389262614623957, -0.25450849718749297,
 3.923821602364237e-15, 0.2545084971874426, 0.29389262614623857, 0.30450849718746387, 0.47552825814756955, 0.6, 0.47552825814760036, 0.3045084971874814,
 0.29389262614624995, 0.25450849718747104, -4.511899658209602e-15, -0.25450849718746454, -0.2938926261462282, -0.30450849718746076, -0.4755282581475826, -0.6,
 -0.47552825814758726, -0.30450849718748463, -0.2938926261462602, -0.25450849718747615, -4.6059099260672245e-14, 0.2545084971874594, 0.29389262614621786, 0.3045084971874743,
 0.4755282581475869, 0.6, 0.4755282581475829, 0.30450849718748774, 0.2938926261462476, 0.2545084971874813, 1.7049311774422875e-14, -0.2545084971874543,
 -0.29389262614620754, -0.3045084971874711, -0.47552825814759125, -0.6, -0.47552825814760136, -0.3045084971874742, -0.2938926261462352, -0.25450849718748647,
 -3.919860126290071e-14, 0.25450849718744917, 0.29389262614624295, 0.30450849718746786, 0.4755282581475728, 0.6, 0.4755282581475971, 0.3045084971874774,
 0.29389262614624556, 0.25450849718746454, 3.861052320705535e-14, -0.25450849718747104, -0.29389262614623257, -0.30450849718746476, -0.4755282581475544, -0.6,
 -0.475528258147584, -0.30450849718748063, -0.2938926261462559, -0.2545084971874967, -3.802244515120999e-14, 0.25450849718746593, 0.29389262614622225, 0.3045084971874783,
 0.47552825814755867, 0.6, 0.47552825814757965, 0.30450849718748374, 0.29389262614624323, 0.2545084971875018, 9.012657664960613e-15, -0.2545084971874608,
 -0.2938926261462119, -0.3045084971874751, -0.475528258147563, -0.6, -0.4755282581475753, -0.30450849718748696, -0.29389262614625355, -0.25450849718750695,
 -8.424579609115248e-15, 0.2545084971874557, 0.2938926261462246, 0.3045084971874552, 0.4755282581475761, 0.6, 0.47552825814759375, 0.3045084971874734,
 0.2938926261462414, 0.254508497187485, 3.057386909759309e-14, -0.25450849718745056, -0.29389262614623696, -0.3045084971874521, -0.47552825814755767, -0.6,
 -0.4755282581475807, -0.3045084971874765, -0.29389262614622874, -0.25450849718749013, -2.9985791041747725e-14, 0.2545084971874725, 0.29389262614622663, 0.30450849718746564,
 0.475528258147562, 0.6, 0.4755282581475764, 0.30450849718747974, 0.2938926261462391, 0.2545084971874953, 9.760035554983525e-16, -0.2545084971874674,
 -0.29389262614621625, -0.3045084971874624, -0.4755282581475663, -0.6, -0.47552825814757205, -0.30450849718748285, -0.29389262614624945, -0.25450849718750046,
 -3.879254996529872e-16, 0.2545084971874622, 0.2938926261462287, 0.3045084971874593, 0.4755282581475794, 0.6, 0.4755282581475678, 0.30450849718748607,
 0.29389262614625977, 0.2545084971874785, -2.0015255619237927e-16, -0.25450849718745705, -0.29389262614621836, -0.3045084971874561, -0.4755282581475837, -0.6,
 -0.4755282581475774, -0.3045084971874892, -0.2938926261462474, -0.25450849718748364, -2.1949136932285465e-14, 0.254508497187479, 0.2938926261462308, 0.30450849718746964,
 0.4755282581475653, 0.6, 0.4755282581476046, 0.3045084971874924, 0.29389262614623474, 0.2545084971874888, 2.13610588764401e-14, -0.25450849718744684,
 -0.2938926261462204, -0.30450849718746653, -0.4755282581475696, -0.6, -0.4755282581476003, -0.30450849718747885, -0.29389262614624506, -0.2545084971874939,
 7.648728609809273e-15, 0.25450849718744173, 0.29389262614623307, 0.3045084971874633, 0.4755282581475739, 0.6, 0.475528258147596, 0.3045084971874821,
 0.2938926261462554, 0.254508497187472, -8.236806665654639e-15, -0.2545084971874636, -0.2938926261462227, -0.3045084971874601, -0.475528258147587, -0.6,
 -0.47552825814758287, -0.3045084971874852, -0.29389262614626577, -0.25450849718747715, -4.2334192253227207e-14, 0.2545084971874585, 0.2938926261462124, 0.30450849718747364
};
