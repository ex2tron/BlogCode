const app = getApp()

Page({
    data: {

    },

    onLoad: function() {

    },

    navH5: function() {
        const url = "http://127.0.0.1:5500/index.html";

        wx.navigateTo({
            url: `../h5/h5?url=${url}`,
        })
    }
})