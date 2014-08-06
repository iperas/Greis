#ifndef ExtSpecDataCustomType_h__
#define ExtSpecDataCustomType_h__

#include <QtCore/QByteArray>
#include "CustomType.h"
#include "ECustomTypeId.h"

namespace Greis
{
    class ExtSpecDataCustomType : public CustomType
    {
    public:
        SMART_PTR_T(ExtSpecDataCustomType);

        ExtSpecDataCustomType(const char* p_message, int p_length);
        ExtSpecDataCustomType(int p_size);
        
        virtual ECustomTypeId::Type IdNumber() const { return ECustomTypeId::ExtSpecData; }
        virtual QByteArray ToByteArray() const;
        virtual int Size() const { return _size; }
        virtual bool IsCorrect() const { return _isCorrect; }

        // Spectrum values for n spectrums [dB*0.1]
        const std::vector<Types::i2>& Spec() const { return _spec; }
        std::vector<Types::i2>& Spec() { return _spec; }

        // Min AGC values []
        const std::vector<Types::u1>& Agcmin() const { return _agcmin; }
        std::vector<Types::u1>& Agcmin() { return _agcmin; }

        // Max AGC values []
        const std::vector<Types::u1>& Agcmax() const { return _agcmax; }
        std::vector<Types::u1>& Agcmax() { return _agcmax; }
    private:
        int _size;
        bool _isCorrect;

        std::vector<Types::i2> _spec;
        std::vector<Types::u1> _agcmin;
        std::vector<Types::u1> _agcmax;
    };
}

#endif // ExtSpecDataCustomType_h__
