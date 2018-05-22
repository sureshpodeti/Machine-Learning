# -*- coding: utf-8 -*-
import scrapy


class Tut1Spider(scrapy.Spider):
    name = 'tut1'
    allowed_domains = ['quotes.toscrape.com']
    start_urls = ['http://quotes.toscrape.com/']

    def parse(self, response):
        self.log('I visited :'+response.url)
        yield {
            'text': response.css('span.text::text').extract_first() ,
            'author_name': response.css('small.author::text').extract_first(),
            'tags': response.css('a.tag::text').extract_first()
        }
