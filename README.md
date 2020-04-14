---
layout: post
title: Tümlev İmge (Integral Image)
date: '2019-02-17T22:27:00.000+03:00'
author: Bahri ABACI
categories:
- Görüntü İşleme
- Hızlı Algoritmalar
modified_time: '2019-07-14T23:08:12.843+03:00'
thumbnail: /assets/post_resources/integral_image/thumbnail.png
---

Tümlev imge (integral image) görüntüde belirli bir dikdörtgenin altında kalan piksellerin toplamının hızlı bir şekilde hesaplanması için geliştirilmiş bir yöntemdir. Yöntem ilk olarak 1984 yılında Franklin C. Crow tarafından doku haritalama (texture mapping) algoritmasında kullanılmak üzere önerilse de en yaygın kullanımına 2001 yılında Paul Viola ve Michael Jones tarafından önerilen nesne tespiti algoritması ile ulaşmıştır. Günümüzde tümlev imge, işlem gücü düşük olan sistemlerde veya evrişim çekirdeğinin çok büyük olmasından dolayı yavaş çalışan süzgeçlerin hızlandırılmasında sıklıkla başvurulan bir yöntem olmuştur.

<!--more-->

Bu yazımızda tümlev imge yönteminin çalışma mantığına ve pratikte ne gibi kazançlar sağladığına değineceğiz. 

Tümlev imgede her bir piksel !["(0,0)"](https://render.githubusercontent.com/render/math?math=%280%2c0%29) noktasından kendisine kadar olan tüm piksellerin toplamını göstermektedir. !["M\times N"](https://render.githubusercontent.com/render/math?math=M%5ctimes%20N) boyutunda bir imgenin tümlev imgesinin hesaplanması için !["M\times N"](https://render.githubusercontent.com/render/math?math=M%5ctimes%20N) boyutunda belleğe ihtiyaç duyulmaktadır. Aşağıdaki resimde sol tarafta örnek bir !["3\times 3"](https://render.githubusercontent.com/render/math?math=3%5ctimes%203) imge verilmiş ve bu imgenin tümlevi imgesi hesaplanmıştır.

![tümlev imge][integral_image_colored]

Tümlev imgede (!["T"](https://render.githubusercontent.com/render/math?math=T)) turuncu kare ile seçili piksel değeri !["T(0,1)"](https://render.githubusercontent.com/render/math?math=T%280%2c1%29), orjinal imgede !["I(0,0)+I(0,1)"](https://render.githubusercontent.com/render/math?math=I%280%2c0%29%2bI%280%2c1%29) piksel değerlerinin toplamı ile hesaplanmıştır. Benzer şekilde koyu yeşil ile gösterilen piksel !["T(2,1)"](https://render.githubusercontent.com/render/math?math=T%282%2c1%29), orjinal imgede !["I(0,0)+I(0,1)+I(1,0)+I(1,1,)+I(2,0)+I(2,1)"](https://render.githubusercontent.com/render/math?math=I%280%2c0%29%2bI%280%2c1%29%2bI%281%2c0%29%2bI%281%2c1%2c%29%2bI%282%2c0%29%2bI%282%2c1%29) işlemi ile bulunmuştur. Daha matematiksel bir ifade ile tümlev imge aşağıdaki formül ile hesaplanmaktadır.

!["T(x,y) = \sum_{i=0}^{x}\sum_{j=0}^{y}I(i,j)"](https://render.githubusercontent.com/render/math?math=T%28x%2cy%29%20%3d%20%5csum_%7bi%3d0%7d%5e%7bx%7d%5csum_%7bj%3d0%7d%5e%7by%7dI%28i%2cj%29)
Peki bu hesaplama bize ne kazandırmaktadır? Bu sorunun yanıtını sağ tarafta yer alan imgeyi inceleyerek bulabiliriz. Bu kez orjinal imgede kırmızı ile seçili piksellerin (!["I(1:2,1:2)"](https://render.githubusercontent.com/render/math?math=I%281%3a2%2c1%3a2%29)) toplamını bulmaya çalıştığımızı düşünelim. Resimden yola çıkarak; kırmızı bölgenin altında kalan piksellerin toplamının, (yeşil + sarı bölgenin toplamı) - (mavi + mor bölgenin toplamı) olarak ifade edebileceğimizi görmekteyiz. Sol tarafta yaptığımız açıklamalara paralel olarak da; yeşil bölgenin toplamı = !["T(2,2)"](https://render.githubusercontent.com/render/math?math=T%282%2c2%29), sarı bölgenin toplamı = !["T(0,0)"](https://render.githubusercontent.com/render/math?math=T%280%2c0%29), mavi bölgenin toplamı = !["T(0,2)"](https://render.githubusercontent.com/render/math?math=T%280%2c2%29) ve mor bölgenin toplamı = !["T(2,0)"](https://render.githubusercontent.com/render/math?math=T%282%2c0%29) olduğunu bildiğimizden tümlev imge yardımı ile bu işlem !["\sum_{i=1}^{2}\sum_{j=1}^{2}I(i,j)=45+1-6-12=28"](https://render.githubusercontent.com/render/math?math=%5csum_%7bi%3d1%7d%5e%7b2%7d%5csum_%7bj%3d1%7d%5e%7b2%7dI%28i%2cj%29%3d45%2b1-6-12%3d28) olarak hesaplanır. Daha genel bir durum için bu işlem aşağıdaki şekilde ifade edilebilir.

!["\sum_{i=x_0}^{x_1}\sum_{j=y_0}^{y_1}I(i,j) = T(x_1,y_1)+T(x_0-1,y_0-1)-T(x_1,y_0-1)-T(x_0-1,y_1)"](https://render.githubusercontent.com/render/math?math=%5csum_%7bi%3dx_0%7d%5e%7bx_1%7d%5csum_%7bj%3dy_0%7d%5e%7by_1%7dI%28i%2cj%29%20%3d%20T%28x_1%2cy_1%29%2bT%28x_0-1%2cy_0-1%29-T%28x_1%2cy_0-1%29-T%28x_0-1%2cy_1%29)

Bu formül çok açık olmasa da aslında tümlev imge yaklaşımının ne kadar hızlı olabileceğini ve neden sıklıkla tercih edildiğini çok iyi açıklıyor. Eşitlikte sol taraf yazılımcı gözüyle incelenirse iki tane for döngüsü kullanıldığı ve bu döngülerin boyutunun !["S_x=x_1-x_0+1"](https://render.githubusercontent.com/render/math?math=S_x%3dx_1-x_0%2b1) ve !["S_y=y_1-y_0+1"](https://render.githubusercontent.com/render/math?math=S_y%3dy_1-y_0%2b1) olduğu görülmektedir. Bu ifade !["O(S_xS_y)"](https://render.githubusercontent.com/render/math?math=O%28S_xS_y%29) karmaşıklığına sahiptir. Ancak tümlev imge yardımı ile aynı işlemin sadece dört piksele erişim, !["O(1)"](https://render.githubusercontent.com/render/math?math=O%281%29) karmaşıklıkla yapılabildiği görülmektedir. Bu da işlem performansı açısından aynı işlemin !["S_xS_y"](https://render.githubusercontent.com/render/math?math=S_xS_y) kat daha hızlı yapılabileceği anlamına gelmektedir.
Benzer şekilde !["k\times k"](https://render.githubusercontent.com/render/math?math=k%5ctimes%20k) boyutlu bir evrişim çekirdeği ile !["M\times N"](https://render.githubusercontent.com/render/math?math=M%5ctimes%20N) boyutlu bir imge evrişim yaklaşımı ile filtrelenmek istendiğinde !["O(MNk^2)"](https://render.githubusercontent.com/render/math?math=O%28MNk%5e2%29) karmaşıklığıa sahip olacakken bu işlem tümlev imge ile !["O(MN)"](https://render.githubusercontent.com/render/math?math=O%28MN%29) karmaşıklığında yapılabilmektedir. Toplam işlem yükü özellikle !["k > 3"](https://render.githubusercontent.com/render/math?math=k%20%3e%203) gibi değerler için !["O(MNk^2)"](https://render.githubusercontent.com/render/math?math=O%28MNk%5e2%29) ile kıyaslandığında oldukça efektif olduğundan tümlev imge kullanımı pratikte oldukça büyük avantajlar sağlamaktadır. Tabi tümlev imgeyi hesaplamanın bize hiç bir maliyeti olmadığını düşünürsek!


Ne mutlu ki tümlev imge imge üzerinden tek bir geçiş !["O(MN)"](https://render.githubusercontent.com/render/math?math=O%28MN%29) ile hesaplanabilmektedir. Bu işlemi yapabilmek için tümlev imge hesaplaması ayrı bir bellekte !["T"](https://render.githubusercontent.com/render/math?math=T) tutulur ve !["x,y"](https://render.githubusercontent.com/render/math?math=x%2cy) noktasındaki tümlev imge değerini hesaplamak için, imgenin !["x,y"](https://render.githubusercontent.com/render/math?math=x%2cy) noktasındaki değerine ek olarak, tümlev imgenin bir soldaki, bir üstteki ve bir sol üstteki değerleri de kullanılır. Matematiksel olarak tümlev imge aşağıdaki formül ile hesaplanır:
!["T(x,y) = I(x,y) + T(x,y-1) + T(x-1,y) + T(x-1,y-1)"](https://render.githubusercontent.com/render/math?math=T%28x%2cy%29%20%3d%20I%28x%2cy%29%20%2b%20T%28x%2cy-1%29%20%2b%20T%28x-1%2cy%29%20%2b%20T%28x-1%2cy-1%29)

Tümlev imge hesaplamak için IMLAB görüntü işleme kütüphanesi kullanılarak aşağıdaki fonksiyon yazılmıştır. Fonksiyon, verilen bir girdi imgesi !["I"](https://render.githubusercontent.com/render/math?math=I) için imge üzerinden tek bir geçiş ile tümlev imgeyi !["T"](https://render.githubusercontent.com/render/math?math=T) hesaplamaktadır.

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
Verilen kodda !["x-1"](https://render.githubusercontent.com/render/math?math=x-1) ve !["y-1"](https://render.githubusercontent.com/render/math?math=y-1) ifadeleri !["x=0"](https://render.githubusercontent.com/render/math?math=x%3d0) ve !["y=0"](https://render.githubusercontent.com/render/math?math=y%3d0) durumlarında negatif olacağından, matematiksel ifadeye uygun olarak !["T(x,y)=\begin{cases}0,&x< 0 \lor y< 0 \T(x,y),&otherwise\end{cases}"](https://render.githubusercontent.com/render/math?math=T%28x%2cy%29%3d%5cbegin%7bcases%7d0%2c%26x%3c%200%20%5clor%20y%3c%200%20%5cT%28x%2cy%29%2c%26otherwise%5cend%7bcases%7d) kabul edilmiştir.

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

Çalışmaya ait ilave dosya ve belgeler de [https://github.com/cescript/cescript_blog_integral_image](https://github.com/cescript/cescript_blog_integral_image) github sayfasında paylaşılmıştır. Çalışmada kullanılan IMLAB kütüphanesi hakkında daha detaylı bilgi almak isterseniz de [http://www.cescript.com/2018/12/imlab-goruntu-isleme-kutuphanesi.html](http://www.cescript.com/2018/12/imlab-goruntu-isleme-kutuphanesi.html) yazımıza göz atabilirsiniz.

**Referanslar**
* Crow, Franklin C. "Summed-area tables for texture mapping." ACM SIGGRAPH computer graphics. Vol. 18. No. 3. ACM, 1984.

* Viola, Paul, and Michael Jones. "Rapid object detection using a boosted cascade of simple features." Computer Vision and Pattern Recognition, 2001. CVPR 2001. Proceedings of the 2001 IEEE Computer Society Conference on. Vol. 1. IEEE, 2001.

[RESOURCES]: # (List of the resources used by the blog post)
[integral_image_colored]: /assets/post_resources/integral_image/summed_arear_table_rects_with_colors.png
[integral_image_sample1]: /assets/post_resources/integral_image/ev_box_blur.png
[integral_image_sample2]: /assets/post_resources/integral_image/istanbul_bogazi.png