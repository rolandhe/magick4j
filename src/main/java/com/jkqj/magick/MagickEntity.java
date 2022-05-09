package com.jkqj.magick;

/**
 * ImageMagick实体抽象,支持4中操作
 *
 * @author hexiufeng
 */
public interface MagickEntity {
    /**
     * 获取ImageMagick底层对象的指针
     *
     * @return
     */
    long getHandler();

    /**
     * 销毁ImageMagick底层对象
     */
    void destroy();

    /**
     * 解绑mageMagick底层对象指针，当前类对象不再负责管理和销毁。
     *
     * 注意：被解绑的底层对象指针必须重新绑定到一个新的对象上，且需要手工消耗，否则会造成内存泄漏
     *
     * @return
     */
    long detach();

    /**
     * 绑定mageMagick底层对象指针，如果当前对象已经持有一个mageMagick底层对象指针，需要销毁
     *
     * @param handler
     */
    void attach(long handler);
}
