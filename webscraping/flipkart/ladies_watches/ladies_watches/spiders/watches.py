# -*- coding: utf-8 -*-

import scrapy

class WatchesSpider(scrapy.Spider):
    name = 'watches'
    i = 1
    url = 'https://www.flipkart.com/search?q=ladies%20watches&marketplace=FLIPKART&otracker=start&as-show=on&as=off&page={}'
    start_urls = [url.format(str(i))]



    def parse(self, response):

        # Get the response objects
        objects = response.css('div._3liAhj')  # has length=40
        self.log('object length:'+ str(len(objects)))

        # traverse and get the details of price, rating, offer, buyers
        price = []
        rating = []
        offer = []
        buyer = []

        for object in objects:
            p = object.css('div._1vC4OE::text').extract_first() # dollar sign +string
            r = object.css('div.hGSR34::text').extract_first() #string
            o = object.css('div.VGWI6T > span::text').extract_first()
            b = object.css('span._38sUEc::text').extract_first()

            if p and r and o and b:
                price.append(p)
                rating.append(r)
                offer.append(o)
                buyer.append(b)

        self.log(offer)
        # making data in order
        price = [int(item.replace(',','')[1:]) for item in price]
        rating = [float(item) for item in rating]
        offer = [int(item[:-5]) for item in offer]
        buyer = [int(item.strip('()').replace(',','')) for item in buyer]

        yield {
            'price': price,
            'rating':rating,
            'offer': offer,
            'buyer': buyer
        }


        # change the url
        self.i += 1

        url = self.url.format(str(self.i))
        self.log("i:" + url)
        if self.i <=50:
            yield scrapy.Request(url=url , callback=self.parse)




