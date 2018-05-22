# -*- coding: utf-8 -*-
import scrapy


class Tut3PySpider(scrapy.Spider):
    name = 'tut3.py'
    allowed_domains = ['quotes.toscrape.com']
    start_urls = ['http://quotes.toscrape.com/']

    def parse(self, response):
        self.log('I just visited:'+response.url)
        # get each item
        for quote in response.css('div.quote'):
            item = {
                'author_name':quote.css('small.author::text').extract_first(),
                'text':quote.css('span.text::text').extract_first(),
                'tags':quote.css('a.tag::text').extract()
            }

            yield item

            # get the next button instance
            next_page_url = response.css('li.next > a::attr(href)').extract_first()
            next_page_url = response.urljoin(next_page_url)
            yield scrapy.Request(url=next_page_url, callback=self.parse)

