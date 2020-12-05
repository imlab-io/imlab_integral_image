---
layout: post
title: Tümlev İmge
slug: integral-image
author: Bahri ABACI
categories:
- Görüntü İşleme
- Hızlı Algoritmalar
references: "Summed-Area Tables for Texture Mapping"
thumbnail: /assets/post_resources/integral_image/thumbnail.png
---

Tümlev imge (integral image) görüntüde belirli bir dikdörtgenin altında kalan piksellerin toplamının hızlı bir şekilde hesaplanması için geliştirilmiş bir yöntemdir. Yöntem ilk olarak 1984 yılında Franklin C. Crow tarafından doku haritalama (texture mapping) algoritmasında kullanılmak üzere önerilse de en yaygın kullanımına 2001 yılında Paul Viola ve Michael Jones tarafından önerilen nesne tespiti algoritması ile ulaşmıştır. Günümüzde tümlev imge, işlem gücü düşük olan sistemlerde veya evrişim çekirdeğinin çok büyük olmasından dolayı yavaş çalışan süzgeçlerin hızlandırılmasında sıklıkla başvurulan bir yöntem olmuştur.

<!--more-->

Bu yazımızda tümlev imge yönteminin çalışma mantığına ve pratikte ne gibi kazançlar sağladığına değineceğiz. 

Tümlev imgede her bir piksel <img src="assets/post_resources/math//e660f3b58b414524ec6f827411021073.svg?invert_in_darkmode" align=middle width=36.52973609999999pt height=24.65753399999998pt/> noktasından kendisine kadar olan tüm piksellerin toplamını göstermektedir. <img src="assets/post_resources/math//dc0d766062f00b3bf4ff7af4097991d4.svg?invert_in_darkmode" align=middle width=52.83089789999999pt height=22.465723500000017pt/> boyutunda bir imgenin tümlev imgesinin hesaplanması için <img src="assets/post_resources/math//dc0d766062f00b3bf4ff7af4097991d4.svg?invert_in_darkmode" align=middle width=52.83089789999999pt height=22.465723500000017pt/> boyutunda belleğe ihtiyaç duyulmaktadır. Aşağıdaki resimde sol tarafta örnek bir <img src="assets/post_resources/math//46e42d6ebfb1f8b50fe3a47153d01cd2.svg?invert_in_darkmode" align=middle width=36.52961069999999pt height=21.18721440000001pt/> imge verilmiş ve bu imgenin tümlevi imgesi hesaplanmıştır.

![tümlev imge][integral_image_colored]

Tümlev imgede (<img src="assets/post_resources/math//2f118ee06d05f3c2d98361d9c30e38ce.svg?invert_in_darkmode" align=middle width=11.889314249999991pt height=22.465723500000017pt/>) turuncu kare ile seçili piksel değeri <img src="assets/post_resources/math//e36dc42ffcaa8be46f25fbe9a080444b.svg?invert_in_darkmode" align=middle width=48.41904704999999pt height=24.65753399999998pt/>, orjinal imgede <img src="assets/post_resources/math//782ff771bc72fd0778dd59085a0ca453.svg?invert_in_darkmode" align=middle width=110.18259284999999pt height=24.65753399999998pt/> piksel değerlerinin toplamı ile hesaplanmıştır. Benzer şekilde koyu yeşil ile gösterilen piksel <img src="assets/post_resources/math//da5e83ded5a0c25a0fb05ea9b85eb79c.svg?invert_in_darkmode" align=middle width=48.41904704999999pt height=24.65753399999998pt/>, orjinal imgede <img src="assets/post_resources/math//7610356f30ed109e883b3dd619caa0f5.svg?invert_in_darkmode" align=middle width=378.03604574999997pt height=24.65753399999998pt/> işlemi ile bulunmuştur. Daha matematiksel bir ifade ile tümlev imge aşağıdaki formül ile hesaplanmaktadır.

<p align="center"><img src="assets/post_resources/math//8dc082d2a0b5d66e7260f261245cef0f.svg?invert_in_darkmode" align=middle width=166.89137684999997pt height=47.91110114999999pt/></p>
Peki bu hesaplama bize ne kazandırmaktadır? Bu sorunun yanıtını sağ tarafta yer alan imgeyi inceleyerek bulabiliriz. Bu kez orjinal imgede kırmızı ile seçili piksellerin (<img src="assets/post_resources/math//0afc272293f1b15f6204afbc9da70f9c.svg?invert_in_darkmode" align=middle width=88.88096249999998pt height=24.65753399999998pt/>) toplamını bulmaya çalıştığımızı düşünelim. Resimden yola çıkarak; kırmızı bölgenin altında kalan piksellerin toplamının, (yeşil + sarı bölgenin toplamı) - (mavi + mor bölgenin toplamı) olarak ifade edebileceğimizi görmekteyiz. Sol tarafta yaptığımız açıklamalara paralel olarak da; yeşil bölgenin toplamı = <img src="assets/post_resources/math//c99990693eb0fe9832b429f33ca78319.svg?invert_in_darkmode" align=middle width=48.41904704999999pt height=24.65753399999998pt/>, sarı bölgenin toplamı = <img src="assets/post_resources/math//9bc44af670873a715071dfe333c8b49b.svg?invert_in_darkmode" align=middle width=48.41904704999999pt height=24.65753399999998pt/>, mavi bölgenin toplamı = <img src="assets/post_resources/math//6aebc77ca6d2eb9b37c2801f2a0176cd.svg?invert_in_darkmode" align=middle width=48.41904704999999pt height=24.65753399999998pt/> ve mor bölgenin toplamı = <img src="assets/post_resources/math//d89032604ec150d3118e04ea522bdb95.svg?invert_in_darkmode" align=middle width=48.41904704999999pt height=24.65753399999998pt/> olduğunu bildiğimizden tümlev imge yardımı ile bu işlem <img src="assets/post_resources/math//9691f16de2a3ff25a8bd7bf90327f305.svg?invert_in_darkmode" align=middle width=297.71307885pt height=31.36100879999999pt/> olarak hesaplanır. Daha genel bir durum için bu işlem aşağıdaki şekilde ifade edilebilir.

<p align="center"><img src="assets/post_resources/math//2fd806ec5310f8a30c3d1d3c0ed66942.svg?invert_in_darkmode" align=middle width=557.5193151pt height=47.91110114999999pt/></p>

Bu formül çok açık olmasa da aslında tümlev imge yaklaşımının ne kadar hızlı olabileceğini ve neden sıklıkla tercih edildiğini çok iyi açıklıyor. Eşitlikte sol taraf yazılımcı gözüyle incelenirse iki tane for döngüsü kullanıldığı ve bu döngülerin boyutunun <img src="assets/post_resources/math//7a95aa42eb2c53b056ed72b411d4efda.svg?invert_in_darkmode" align=middle width=122.21431034999999pt height=22.465723500000017pt/> ve <img src="assets/post_resources/math//3a1de962b39163a09a650a7176c625f7.svg?invert_in_darkmode" align=middle width=119.1684318pt height=22.465723500000017pt/> olduğu görülmektedir. Bu ifade <img src="assets/post_resources/math//787832ac2058cd43cfd2984ccb180437.svg?invert_in_darkmode" align=middle width=62.11847729999999pt height=24.65753399999998pt/> karmaşıklığına sahiptir. Ancak tümlev imge yardımı ile aynı işlemin sadece dört piksele erişim, <img src="assets/post_resources/math//1e2f931ee6c0b8e7a51a7b0d123d514f.svg?invert_in_darkmode" align=middle width=34.00006829999999pt height=24.65753399999998pt/> karmaşıklıkla yapılabildiği görülmektedir. Bu da işlem performansı açısından aynı işlemin <img src="assets/post_resources/math//9870c88e7cf098ca132e9c9134f2a442.svg?invert_in_darkmode" align=middle width=35.51572364999999pt height=22.465723500000017pt/> kat daha hızlı yapılabileceği anlamına gelmektedir.
Benzer şekilde <img src="assets/post_resources/math//649b7f492ffd7b6c6f42429f3fe29451.svg?invert_in_darkmode" align=middle width=38.24192129999999pt height=22.831056599999986pt/> boyutlu bir evrişim çekirdeği ile <img src="assets/post_resources/math//dc0d766062f00b3bf4ff7af4097991d4.svg?invert_in_darkmode" align=middle width=52.83089789999999pt height=22.465723500000017pt/> boyutlu bir imge evrişim yaklaşımı ile filtrelenmek istendiğinde <img src="assets/post_resources/math//6667de67275b90027967e1cec1e51966.svg?invert_in_darkmode" align=middle width=74.97036524999999pt height=26.76175259999998pt/> karmaşıklığıa sahip olacakken bu işlem tümlev imge ile <img src="assets/post_resources/math//8599389c4762b742e7af1c293135bf1d.svg?invert_in_darkmode" align=middle width=58.52054174999999pt height=24.65753399999998pt/> karmaşıklığında yapılabilmektedir. Toplam işlem yükü özellikle <img src="assets/post_resources/math//e6f36f14a108f8da14c08abfb7c9a944.svg?invert_in_darkmode" align=middle width=39.21220214999999pt height=22.831056599999986pt/> gibi değerler için <img src="assets/post_resources/math//6667de67275b90027967e1cec1e51966.svg?invert_in_darkmode" align=middle width=74.97036524999999pt height=26.76175259999998pt/> ile kıyaslandığında oldukça efektif olduğundan tümlev imge kullanımı pratikte oldukça büyük avantajlar sağlamaktadır. Tabi tümlev imgeyi hesaplamanın bize hiç bir maliyeti olmadığını düşünürsek!


Ne mutlu ki tümlev imge imge üzerinden tek bir geçiş <img src="assets/post_resources/math//8599389c4762b742e7af1c293135bf1d.svg?invert_in_darkmode" align=middle width=58.52054174999999pt height=24.65753399999998pt/> ile hesaplanabilmektedir. Bu işlemi yapabilmek için tümlev imge hesaplaması ayrı bir bellekte <img src="assets/post_resources/math//2f118ee06d05f3c2d98361d9c30e38ce.svg?invert_in_darkmode" align=middle width=11.889314249999991pt height=22.465723500000017pt/> tutulur ve <img src="assets/post_resources/math//0acac2a2d5d05a8394e21a70a71041b4.svg?invert_in_darkmode" align=middle width=25.350096749999988pt height=14.15524440000002pt/> noktasındaki tümlev imge değerini hesaplamak için, imgenin <img src="assets/post_resources/math//0acac2a2d5d05a8394e21a70a71041b4.svg?invert_in_darkmode" align=middle width=25.350096749999988pt height=14.15524440000002pt/> noktasındaki değerine ek olarak, tümlev imgenin bir soldaki, bir üstteki ve bir sol üstteki değerleri de kullanılır. Matematiksel olarak tümlev imge aşağıdaki formül ile hesaplanır:
<p align="center"><img src="assets/post_resources/math//2816556a5012c06954f8b1e910aed4c8.svg?invert_in_darkmode" align=middle width=442.1835693pt height=16.438356pt/></p>

Tümlev imge hesaplamak için IMLAB görüntü işleme kütüphanesi kullanılarak aşağıdaki fonksiyon yazılmıştır. Fonksiyon, verilen bir girdi imgesi <img src="assets/post_resources/math//21fd4e8eecd6bdf1a4d3d6bd1fb8d733.svg?invert_in_darkmode" align=middle width=8.515988249999989pt height=22.465723500000017pt/> için imge üzerinden tek bir geçiş ile tümlev imgeyi <img src="assets/post_resources/math//2f118ee06d05f3c2d98361d9c30e38ce.svg?invert_in_darkmode" align=middle width=11.889314249999991pt height=22.465723500000017pt/> hesaplamaktadır.

```c
void compute_integral_image(matrix_t *I, matrix_t *T)
{
    uint32_t x, y;

    // handle the x=0,y=0 case
    atf(T, 0, 0) = atui8(I, 0, 0);
    
    /* compute the table completely */
    for (y = 1; y < height(I); y++)
    {
        // handle the zero case
        atf(T, y, 0) = atui8(I, y, 0);

        // do the calculation for x > 0
        for (x = 1; x < width(I); x++)
        {
            atf(T, y, x) = atui8(I, y, x) + atf(T, y, x - 1) + atf(T, y - 1, x) - atf(T, y - 1, x - 1);
        }
    }
}
```
Verilen kodda <img src="assets/post_resources/math//6e2a027fd5d65c9f49f111b1fa539e7a.svg?invert_in_darkmode" align=middle width=37.70538914999999pt height=21.18721440000001pt/> ve <img src="assets/post_resources/math//ae6230e5e2730e024609c8c96a9094a7.svg?invert_in_darkmode" align=middle width=36.95960729999999pt height=21.18721440000001pt/> ifadeleri <img src="assets/post_resources/math//8436d02a042a1eec745015a5801fc1a0.svg?invert_in_darkmode" align=middle width=39.53182859999999pt height=21.18721440000001pt/> ve <img src="assets/post_resources/math//a42b1c71ca6ab3bfc0e416ac9b587993.svg?invert_in_darkmode" align=middle width=38.78604674999999pt height=21.18721440000001pt/> durumlarında negatif olacağından, matematiksel ifadeye uygun olarak 

<p align="center"><img src="assets/post_resources/math//9ab2b8055a804cbff5500c3ac679bd6f.svg?invert_in_darkmode" align=middle width=252.79645709999997pt height=49.315569599999996pt/></p> kabul edilmiştir.

Çalışmada tümlev imge kullanımına örnek olarak **box blur** süzegecinin gerçeklenmesi yapılmıştır. Bu süzgeç tamamı birlerden oluşan basit bir görüntü bulanıklaştırma süzgecidir. Evrişimin mantığı gereği tamamı birlerden oluşan bir çekirdek ile yapılan evrişim işlemi, çekirdeğin altında kalan alanın toplamına karşılık gelmektedir. Bu nedenle bu süzgecin tümlev imge yardımı ile gerçeklenmesi mümkün olmaktadır. Tümlev imge yardımı ile **box blur** süzegecinin gerçeklenmesi için IMLAB görüntü işleme kütüphanesi kullanılarak aşağıdaki kod yazılmıştır.

```c
int main(int argc, char *argv[]) 
{
    int k,m,n;

    // maximum half filter size
    int hfilterSize = 20;

    // read the source image and its mask
    matrix_t *img = imread("../data//ev.bmp");
    matrix_t *mask = imread("../data//ev_mask.bmp");

    // allocate space for filtered and integral images
    matrix_t *filtered = matrix_create(uint8_t, rows(img), cols(img), 3);
    matrix_t *integral = matrix_create(float, rows(img), cols(img), 3);

    // compute the integral image
    compute_integral_image(img, integral);

    // run over the image and compute the box blur
    for (n = hfilterSize; n < height(img) - hfilterSize; n++)
    {
        for (m = hfilterSize; m < width(img) - hfilterSize; m++)
        {
            // estimate the filter size wrt mask value
            int filterSize = map(atui8(mask, n, m, 0), 0,255, 1,hfilterSize);

            // pre calculate the normalizer for the box
            float areaInv = 1.0f / ((2 * filterSize + 1) * (2 * filterSize + 1));

            // filter the channels seperately
            for (k = 0; k < channels(img); k++)
            {
                atui8(filtered, n, m, k) = clamp(areaInv * get_integral(integral, m - filterSize, n - filterSize, m + filterSize, n + filterSize, k), 0, 255);
            }
        }
    }

    // write the filtered image
    imwrite(filtered, "filtered.bmp");

    return 0;
}
```

Kodda bulanıklaştırma işlemini daha karmaşık hale getirmek ve ilginç sonuçlar elde edebilmek için süzgecin büyüklüğü maske adı verilen ikinci bir imge ile kontrol edilebilir yapılmıştır. Bu sayede resmin bazı bölgeleri bulanık yapılırken bazı bölgelerinin olduğu gibi kalabilmesi sağlanmıştır.
Kodun farklı maske ve imgelerle çalıştırılması sonucu elde edilen bazı örneklerde aşağıda verilmiştir.

![tümlev imge filtre uygulaması][integral_image_sample1]
![tümlev imge filtre uygulaması][integral_image_sample2]

Çalışmaya ait ilave dosya ve belgeler de [https://github.com/cescript/cescript_blog_integral_image](https://github.com/cescript/cescript_blog_integral_image) github sayfasında paylaşılmıştır. Çalışmada kullanılan IMLAB kütüphanesi hakkında daha detaylı bilgi almak isterseniz de [IMLAB Göruntü İşleme Kütüphanesi]({% post_url 2018-12-03-imlab-goruntu-isleme-kutuphanesi %}) yazımıza göz atabilirsiniz.

**Referanslar**
* Crow, Franklin C. "Summed-area tables for texture mapping." ACM SIGGRAPH computer graphics. Vol. 18. No. 3. ACM, 1984.

* Viola, Paul, and Michael Jones. "Rapid object detection using a boosted cascade of simple features." Computer Vision and Pattern Recognition, 2001. CVPR 2001. Proceedings of the 2001 IEEE Computer Society Conference on. Vol. 1. IEEE, 2001.

[RESOURCES]: # (List of the resources used by the blog post)
[integral_image_colored]: /assets/post_resources/integral_image/summed_arear_table_rects_with_colors.png
[integral_image_sample1]: /assets/post_resources/integral_image/ev_box_blur.png
[integral_image_sample2]: /assets/post_resources/integral_image/istanbul_bogazi.png