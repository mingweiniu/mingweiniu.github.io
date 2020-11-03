function changeCategoryHeader() {
    var imgs = [
        ['https://i.imgur.com/CJKEi42.jpg', 'https://i.imgur.com/HrD1sPM.jpg'],
        ['https://i.imgur.com/dqPja7q.jpg', 'https://i.imgur.com/36tMcuh.jpg'],
        ['https://i.imgur.com/qlJDTVH.jpg', 'https://i.imgur.com/KQ0iddk.jpg'],
        ['https://i.imgur.com/pCboCoJ.jpg', 'https://i.imgur.com/A6V6XD2.jpg'],
        ['https://i.imgur.com/HDbb58o.jpg', 'https://i.imgur.com/5c6yfyS.jpg'],
        ['https://i.imgur.com/bSShncN.jpg', 'https://i.imgur.com/H99GBP6.jpg'],
        ['https://i.imgur.com/yxuDfDz.jpg', 'https://i.imgur.com/7bI32Rb.jpg'],
        ['https://i.imgur.com/8uSsS4A.jpg', 'https://i.imgur.com/U7wFApB.jpg']
    ];

    var paths = [
        "/wd2/archives/category/feature",
        "/wd2/archives/category/feature/%e7%8e%a9%e9%85%b7%e5%ad%90%e5%bc%9f",
        "/wd2/archives/category/feature/%e9%80%b1%e4%ba%94%e7%90%83%e9%9e%8b%e6%bf%80%e6%8e%a8",
        "/wd2/archives/category/feature/%e7%a9%bf%e6%90%ad%e8%ac%9b%e5%a0%82",
        "/wd2/archives/category/feature/%e5%a6%b9%e5%ad%90%e8%a1%a3%e6%ab%83",
        "/wd2/archives/category/feature/%e6%bd%ae%e6%b5%81%e7%a4%be%e8%ab%96",
        "/wd2/archives/category/feature/%e9%80%b1%e6%9c%ab%e6%bd%ae%e7%b4%9a%e5%ae%85",
        "/wd2/archives/category/feature/cool-girl-feature"
    ];

    var path = document.location.pathname;
    var img = null;
    for (var i = 0; i < paths.length; i++) {
        if (path.endsWith(paths[i]) || path.includes(paths[i] + '/page/')) {
            img = imgs[i];
        }
    }
    if (null != img && img[0] && img[1]) {
        jQuery('.main-body .main-title').html('<img width="100%" src="' + img[0] + '" class="title-desktop"><img width="100%" src="' + img[1] + '" class="title-mobile">');
        jQuery('head').append('<style> .title-mobile { display: none; } @media screen and (max-width: 768px) { .title-mobile { display: block; } .title-desktop { display: none; } } </style>');
    }
    jQuery('.main-body .main-title').show();
}

jQuery(function() {
    jQuery('#shadowfiend_carousel-3 .post-cat, #shadowfiend_carousel-3 .post-title').hide();
    jQuery('body').on('click', '#shadowfiend_masonry-4 .loadmore-button', function(e) {
        window.location.href = 'https://www.cool-style.com.tw/wd2/archives/category/fahsion';
    });
    jQuery('body').on('click', '#shadowfiend_masonry-5 .loadmore-button', function(e) {
        window.location.href = 'https://www.cool-style.com.tw/wd2/archives/category/sneaker';
    });
    jQuery('body').on('click', '#shadowfiend_masonry-6 .loadmore-button', function(e) {
        window.location.href = 'https://www.cool-style.com.tw/wd2/archives/category/entertainment-2';
    });

    changeCategoryHeader();
});
